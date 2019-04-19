#include <um/UpdateManager.h>

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
    int msec = 1000/m_fps;
    m_timer.SetTimer(msec,std::bind(&um::UpdateManager::_world_update,this,placeholders::_1));
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

void um::UpdateManager::_world_update(float dt)
{
    m_engine.world_update(dt);
}

void um::UpdateManager::_action_update(Event ev)
{
    for(int i=0;i<ev.actionNum();i++)
        m_engine.action_update(ev.action(i));\
}
