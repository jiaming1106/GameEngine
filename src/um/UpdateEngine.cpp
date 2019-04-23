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

void um::UpdateEngine::world_update(float dt)
{
    vector<OperatorHandle> died_op;
    auto it = m_world->update_list_begin();
    for(;it!=m_world->update_list_end();++it){
        /**< if returned that the OP need to be deleted, del it from the update list later */
        if(!(it->second)->onUpdate(dt))
            died_op.push_back(it->first);
        /**< NOT GOOD JUST TEST */
        db.update_operator(it->second);
    }
    for(OperatorHandle eo : died_op)
    {
        m_world->inactivate(eo);
        db.del_operator(eo);
    }
}

void um::UpdateEngine::action_update(Action act)
{
    cout<<"\033[31m\033[47m";
    /**< BAD CODING */
    if(act.arg(0).m_asHandle<0)
    {
        m_world->onAction(act);
    }

    /**< Get the OperatorHandle which will do this action */
    auto it = m_world->find(act.arg(0).m_asHandle);
    if(it!=m_world->end())
    {
        /**< if returned that the OP need to be updated, insert it to the update list*/
        /**< seems useless now */
        if(it->second->onAction(act))
            m_world->activate(it->first);
    }
    cout<<"\033[0m";
}
