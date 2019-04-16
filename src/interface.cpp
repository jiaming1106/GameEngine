#include "interface.h"
#include "umAction.h"
#include "umDecisionFactory.h"
#include "MoveDecision.h"
#include "ShootDecision.h"
#include <vector>
#include <iostream>

using namespace um;

interface::interface()
{
    //ctor
    /**< TODO : init from a config files AND
    move to a new class to keep the interface clean*/
    REGISTERDECISION(MoveDecision);
    REGISTERDECISION(ShootDecision);
}

interface::~interface()
{
    //dtor
}

void interface::input(UsrInput input)
{
    shared_ptr<Decision> dec = _map(input);
    if(dec){
        if(dec->check()){
            vector<Action> act_list;
            dec->genAction(act_list);
            /**<  TODO : push into UpdateManager one by one or a list? */
        }else{

        }
    }
    else{
        cout<<"Game : Unsupported User Input"<<endl;
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
    if(!input.compare("1"))
        dt = "MoveDecision";
    else if(!input.compare("2"))
        dt = "ShootDecision";

    return dt;
}

