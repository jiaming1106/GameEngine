#include "ShootDecision.h"
#include <iostream>

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

    return true;
}

void ShootDecision::genAction(vector<Action>& act_list)
{
    /**< TODO : Select meta act from action library*/
    cout<<"Decision - Shoot : exec"<<endl;
    um::Variant arg1(um::Variant::TYPE_INT);
    arg1.m_asInt = 65;
    um::Variant arg2(um::Variant::TYPE_FLOAT);
    arg2.m_asFloat = 32.5;
    cout<<"Shoot Event : "<<arg1.m_asInt<<" "<<arg2.m_asFloat<<endl;
}
