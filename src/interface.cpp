#include "interface.h"
#include "umAction.h"
#include "umDecisionFactory.h"
#include "MoveDecision.h"
#include "ShootDecision.h"
#include <vector>

using namespace um;

interface::interface()
{
    //ctor
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
    /**<  TODO : Assert map is OK? */

    if(dec->check()){
        vector<Action> act_list;
        dec->exec(act_list);
        /**<  TODO : push into Manager one by one or a list? */
    }
}

shared_ptr<Decision> interface::_map(const UsrInput usr_input)
{
    DecisionType dt  = getDecisionType(usr_input);
    shared_ptr<Decision> dc = DecisionFactory::instance()->CreatDecision(dt);
    dc->setCommand(usr_input);
    return dc;
}

DecisionType interface::getDecisionType(const UsrInput input)
{
    DecisionType dt;
    /**< TODO : Read Type From Input */
    /**< MakeSure the MAP the same as the RegisterClass */
    if(!input.compare("1"))
        dt = "MoveDecision";
    else if(!input.compare("2"))
        dt = "ShootDecision";
    return dt;
}

