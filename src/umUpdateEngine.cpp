#include "umUpdateEngine.h"
#include <umMarco.h>
#include <iostream>

using namespace std;
using namespace um;

um::UpdateEngine::UpdateEngine()
{
    //ctor
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

void um::UpdateEngine::action_update(Action action)
{
    cout<<"Engine : Player "<<endl;
    //InsTaskList tl = action.get
    world_update();
}
