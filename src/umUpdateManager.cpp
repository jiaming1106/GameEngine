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

void um::UpdateManager::onStart()
{
    int msec = 3000;
    m_timer.SetTimer(msec,std::bind(&um::UpdateManager::_world_update,this));
    m_timer.Start();
}

void um::UpdateManager::onPause()
{
    m_timer.Stop();
}

void um::UpdateManager::onStop()
{
    m_timer.Stop();
}

void um::UpdateManager::onEvent(const Event ev)
{
    _action_update(ev);
}

void um::UpdateManager::_world_update()
{
    m_engine.world_update();
}

void um::UpdateManager::_action_update(Event ev)
{
    for(int i=0;i<ev.actionNum();i++)
        m_engine.action_update(ev.action(i));
}
