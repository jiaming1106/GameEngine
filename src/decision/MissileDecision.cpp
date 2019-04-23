#include "MissileDecision.h"
#include <um/Action.h>
#include <um/Event.h>
#include <iostream>
#include <sstream>

MissileDecision::MissileDecision()
{
    //ctor
}

MissileDecision::~MissileDecision()
{
    //dtor
}

bool MissileDecision::check()
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

Event MissileDecision::genEvent()
{
    Action act1(ActionType("MISSILE"));
    um::Variant arg1(um::Variant::TYPE_HANDLE);
    arg1.m_asHandle = -1;
    act1.addArg(arg1);
    um::Variant arg2(um::Variant::TYPE_HANDLE);
    arg2.m_asHandle = m_bop_att;
    act1.addArg(arg2);

    Event sht_ev(act1);

    return sht_ev;
}

bool MissileDecision::_parse()
{
    stringstream ss(m_command);
    string buf;
    /**< DANGEROUS */
    ss>>buf;
    ss>>m_bop_att;
    return true;
}
