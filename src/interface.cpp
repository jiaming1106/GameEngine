#include "interface.h"
#include <um/Action.h>
#include <um/DecisionFactory.h>
#include <um/Event.h>

#include <vector>
#include <iostream>
#include <sstream>

#include <decision/MoveDecision.h>
#include <decision/ShootDecision.h>
#include <decision/StopDecision.h>

using namespace um;

interface::interface()
{
    /**< TODO : init from a config files AND
    move to a new class to keep the interface clean*/
    REGISTERDECISION(MoveDecision);
    REGISTERDECISION(ShootDecision);
    REGISTERDECISION(StopDecision);
}

interface::~interface()
{

}

void interface::input(UsrInput input)
{
    shared_ptr<Decision> dec = _map(input);
    if(dec){
        /**< CHECK */
        if(dec->check()){
            Event dev_ev = dec->genEvent();
            /**< SEND */
            m_um.onEvent(dev_ev);
        }else{
            cout<<"Game : Decision violate some rules."<<endl;
        }
    }
}

shared_ptr<Decision> interface::_map(const UsrInput usr_input)
{
    DecisionType dt  = _getDecisionType(usr_input);
    if(dt.empty()){
        return NULL;
    }else{
        shared_ptr<Decision> dc = DecisionFactory::instance()->CreatDecision(dt);
        dc->setCommand(usr_input);
        return dc;
    }
}

DecisionType interface::_getDecisionType(const UsrInput input)
{
    DecisionType dt;
    /**< TODO : Read Type From Input */
    /**< Maybe Map from a unified config file as the Register*/
    /**< MakeSure the MAP the same as the RegisterClass */
    /**< BAD CODING */
    if(input.at(0)=='-'){
        /**< Maybe MAP is better */
        if (!input.compare("-s")){
            m_um.onStart();
            cout<<"GAME START"<<endl;
        }else if (!input.compare("-p")){
            m_um.onPause();
            cout<<"GAME Pause"<<endl;
        }else if (!input.compare("-q")){
            m_um.onStop();
            cout<<"GAME OVER"<<endl;
        }
    }else{
        stringstream ss(input);
        string buf;
        ss>>buf;
        /**< Maybe MAP is better */
        if(!buf.compare("mov"))
            dt = "MoveDecision";
        else if(!buf.compare("att"))
            dt = "ShootDecision";
        else if(!buf.compare("stop"))
            dt = "StopDecision";
    }
    return dt;
}

