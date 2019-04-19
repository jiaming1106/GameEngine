#include <um/UpdateEngine.h>
#include <um/Marco.h>
#include <iostream>

#include <operator/Tank.h>

using namespace std;
using namespace um;

um::UpdateEngine::UpdateEngine()
{
    /**< Just for test, should be moved to a GameWorld -- */
    shared_ptr<Tank> t1(new Tank(0,3,0));
    shared_ptr<Tank> t2(new Tank(1,3,10));
    _insert(0,t1);
    _insert(1,t2);
    /**< Just for test, should be moved to a GameWorld -- */

    m_worldstep = 0.1;
}

um::UpdateEngine::~UpdateEngine()
{
    //dtor
}

bool um::UpdateEngine::_insert(OperatorHandle op_h, shared_ptr<Operator> op)
{
    auto ret = m_op_list.insert(pair<OperatorHandle,shared_ptr<Operator>>(op_h,op));
    return ret.second;
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
    auto it = m_op_list.find(act.arg(0).m_asHandle);
    if(it!=m_op_list.end())
        it->second->onAction(act);
}
