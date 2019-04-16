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
    /**< TODO : Select check rules from rules library*/
    /**< write the hard rules first
    then change it into config files*/

    return true;
}

void MoveDecision::genAction(vector<Action>& act_list)
{
    /**< TODO : Select meta act from action library*/
    cout<<"Decision - Move : exec"<<endl;

}
