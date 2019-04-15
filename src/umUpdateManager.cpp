#include "umUpdateManager.h"

#include <functional>
#include <assert.h>

using namespace um;

um::UpdateManager::UpdateManager()
{
    //ctor
}

um::UpdateManager::~UpdateManager()
{
    //dtor
}

void um::UpdateManager::loop_start()
{
    int msec = 3000;
    m_timer.SetTimer(msec,std::bind(&um::UpdateManager::_world_update,this));
    m_timer.Start();
}

void um::UpdateManager::loop_pause()
{
    m_timer.Stop();
}

void um::UpdateManager::loop_stop()
{
    m_timer.Stop();
}

void um::UpdateManager::update(Action action)
{
    _action_update(action);
}

void um::UpdateManager::_world_update()
{
    m_engine.world_update();
}

void um::UpdateManager::_action_update(Action action)
{
    m_engine.action_update(action);
}
