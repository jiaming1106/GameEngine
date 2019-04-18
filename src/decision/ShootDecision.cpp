#include <decision/ShootDecision.h>
#include <um/Action.h>
#include <um/Event.h>
#include <iostream>
#include <sstream>

ShootDecision::ShootDecision()
{
    //ctor
}

ShootDecision::~ShootDecision()
{
    //dtor
}

bool ShootDecision::check()
{
    /**< TODO : Select check rules from rules library*/
    /**< write the hard rules first
    then change it into config files*/
    if(_parse())
    {
        /**< there needs a judge */
        m_damage = 1;
        return true;
    }else
    {
        return false;
    }
}

bool ShootDecision::_parse()
{
    stringstream ss(m_command);
    string buf;
    /**< DANGEROUS */
    ss>>buf;
    ss>>m_bop_att;
    ss>>m_bop_obj;
    return true;
}

Event ShootDecision::genEvent()
{
    Action act1(ActionType("SHOOT"));
    um::Variant arg1(um::Variant::TYPE_INT);
    arg1.m_asInt = m_bop_att;
    act1.addArg(arg1);

    Action act2(ActionType("INJURY"));
    um::Variant arg2(um::Variant::TYPE_INT);
    arg2.m_asInt = m_bop_obj;
    act2.addArg(arg2);
    um::Variant arg3(um::Variant::TYPE_INT);
    arg3.m_asInt = m_damage;
    act2.addArg(arg3);

    Event sht_ev(act1);
    sht_ev.addAction(act2);

    return sht_ev;
}
