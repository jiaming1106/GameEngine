#include "MoveToDecision.h"
#include <um/Event.h>
#include <um/Action.h>
#include <iostream>
#include <sstream>

MoveToDecision::MoveToDecision()
{
    //ctor
}

MoveToDecision::~MoveToDecision()
{
    //dtor
}

bool MoveToDecision::check()
{
    /**< TODO : Select check rules from rules library*/
    /**< write the hard rules first
    then change it into config files*/
    if(_parse())
    {
        return true;
    }else
    {
        return false;
    }
}

Event MoveToDecision::genEvent()
{
//define action type
    Action mv_act(ActionType("MOVETO"));

//add action arguments
    um::Variant arg1(um::Variant::TYPE_HANDLE);
    arg1.SetData(m_move_bop);
    mv_act.addArg(arg1);

    um::Variant arg2(um::Variant::TYPE_INT);
    arg2.SetData(m_move_path);
    mv_act.addArg(arg2);

//generate event
    Event mv_ev(mv_act);

    return mv_ev;
}

bool MoveToDecision::_parse()
{
    stringstream ss(m_command);
    string buf;
    /**< Really NOT SAFE */
    ss>>buf;
    ss>>m_move_bop;
    ss>>m_move_path;
    return true;
}
