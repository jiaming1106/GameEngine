#include "MoveDecision.h"
#include <iostream>

MoveDecision::MoveDecision()
{
    //ctor
}

MoveDecision::~MoveDecision()
{
    //dtor
}

bool MoveDecision::check()
{
    return true;
}

bool MoveDecision::exec(vector<Action>& act_list)
{
    cout<<"Decision : Move"<<endl;
    return true;
}
