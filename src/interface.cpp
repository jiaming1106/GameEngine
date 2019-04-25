#include "interface.h"
#include <um/Action.h>
#include <um/DecisionFactory.h>
#include <um/Event.h>

#include <vector>
#include <iostream>
#include <sstream>

using namespace um;

interface::interface()
{

}

interface::~interface()
{

}

void interface::input(UsrInput input)
{
    // get the decision
    shared_ptr<Decision> dec = _map(input);
    if(dec){
        /**< CHECK DECISION */
        if(dec->check()){
            /**< GEN EVENT */
            Event dev_ev = dec->genEvent();
            /**< SEND THE EVENT */
            m_um.onEvent(dev_ev);
        }else{
            cout<<"Game : Decision violate some rules."<<endl;
        }
    }
}

shared_ptr<Decision> interface::_map(const UsrInput usr_input)
{
    shared_ptr<Decision> dc = NULL;
    // map Input to Decision Class Name
    DecisionType dt  = _getDecisionType(usr_input);
    if(!dt.empty()){
        // new a dt type Decision
        dc = DecisionFactory::instance()->CreatDecision(dt);
        dc->setCommand(usr_input);
    }
    return dc;
}

DecisionType interface::_getDecisionType(const UsrInput input)
{
    DecisionType dt;
    if(input.empty()) return dt;
    if(input.at(0)=='-'){
        cout<<"\033[33m";
        /**< Maybe MAP is better */
        if (!input.compare("-s")){
            m_um.onStart();
            cout<<"GAME START"<<endl;
        }else if (!input.compare("-p")){
            m_um.onPause();
            cout<<"GAME PAUSE"<<endl;
        }else if (!input.compare("-q")){
            m_um.onStop();
            cout<<"GAME OVER"<<endl;
        }
        cout<<"\033[0m";
    }else{
        /**< BAD CODING */
        stringstream ss(input);
        ss>>dt;
    }
    return dt;
}
