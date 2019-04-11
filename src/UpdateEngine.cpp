#include "UpdateEngine.h"
#include <iostream>
using namespace std;

UpdateEngine::UpdateEngine()
{
    //ctor
    m_worldstep = 0.1;
}

UpdateEngine::~UpdateEngine()
{
    //dtor
}

void UpdateEngine::world_update()
{
    m_worldstep += 0.01;
    cout<<"Engine : World "<<m_worldstep<<endl;
}

void UpdateEngine::action_update(umAction action)
{
    cout<<"Engine : Player "<<action<<endl;
    world_update();
}
