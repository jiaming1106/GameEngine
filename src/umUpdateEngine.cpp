#include "umUpdateEngine.h"
#include <umMarco.h>
#include <iostream>

#include "Tank.h"

using namespace std;
using namespace um;

um::UpdateEngine::UpdateEngine()
{
    /**< Just for test, should be move a Initiator -- */
    shared_ptr<Tank> t1(new Tank(0,5,0));
    shared_ptr<Tank> t2(new Tank(1,5,10));
    m_op_list.push_back(t1);
    m_op_list.push_back(t2);
    /**< Just for test, should be move a Initiator -- */

    m_worldstep = 0.1;
}

um::UpdateEngine::~UpdateEngine()
{
    //dtor
}

void um::UpdateEngine::world_update()
{
    m_worldstep += 0.01;
    cout<<"Engine : World "<<m_worldstep<<endl;
}

void um::UpdateEngine::action_update(Action act)
{
    m_op_list.at(act.arg(0).m_asInt)->onAction(act);
}
