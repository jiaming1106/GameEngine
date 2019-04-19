#include <um/UpdateEngine.h>
#include <um/Marco.h>
#include <iostream>

#include <operator/Tank.h>

using namespace std;
using namespace um;


um::UpdateEngine::UpdateEngine(shared_ptr<GameWorld> ww)
{
    m_world = ww;
}

um::UpdateEngine::~UpdateEngine()
{
    //dtor
}

bool um::UpdateEngine::_insert(OperatorHandle op_h)
{
    /**< TODO : some check */
    m_op_list.insert(pair<OperatorHandle, shared_ptr<Operator>>(op_h,(*m_world)[op_h]));
    return true;
}

void um::UpdateEngine::_del(OperatorHandle op_h)
{
    m_op_list.erase(op_h);
}

void um::UpdateEngine::world_update(float dt)
{
    vector<OperatorHandle> died_op;
    for(auto it : m_op_list){
        if(!(it.second)->onUpdate(dt))
            died_op.push_back(it.first);
    }
    for(OperatorHandle eo : died_op)
    {
        m_op_list.erase(eo);
    }

}

void um::UpdateEngine::action_update(Action act)
{
    auto it = m_world->find(act.arg(0).m_asHandle);
    if(it!=m_world->end())
    {
        cout<<"\033[31m\033[47m";
        if(it->second->onAction(act))
            _insert(it->first);
        cout<<"\033[0m";
    }
}
