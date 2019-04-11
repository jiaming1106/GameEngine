#include "UpdateManager.h"
#include<functional>
#include <thread>

#include <assert.h>

UpdateManager::UpdateManager()
{
    //ctor
}

UpdateManager::~UpdateManager()
{
    //dtor
}

void UpdateManager::loop_start()
{
    int msec = 4000;
    m_timer.SetTimer(msec,std::bind(&UpdateManager::_world_update,this));
    m_timer.Start();
}

void UpdateManager::loop_pause()
{
    m_timer.Stop();
}

void UpdateManager::loop_stop()
{
    m_timer.Stop();
}

void UpdateManager::update(umAction action)
{
    _action_update(action);
}

void UpdateManager::_world_update()
{
    m_engine.world_update();
}

void UpdateManager::_action_update(umAction action)
{
    m_engine.action_update(action);
}
