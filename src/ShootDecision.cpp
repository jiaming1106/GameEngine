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
    return true;
}

bool ShootDecision::exec(vector<Action>& act_list)
{
    cout<<"Decision : Shoot"<<endl;
    return true;
}
