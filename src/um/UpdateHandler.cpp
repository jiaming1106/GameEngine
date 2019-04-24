#include "um/UpdateHandler.h"
#include <vector>

namespace um {

UpdateHandler::UpdateHandler()
{
    //ctor
}

UpdateHandler::~UpdateHandler()
{
    //dtor
}

int UpdateHandler::onUpdate(float dt)
{
    vector<string> end_state;
    for(auto it : m_map_update)
    {
        int ans = (it.second)->update(dt);
        if(ans == 1 ) end_state.push_back(it.first);
    }

    /**< delete the  sustained action WHEN it finished*/
    for(auto et : end_state)
    {
        m_map_update.erase(et);
    }

    return 1;
}

void UpdateHandler::_del_upt(string type)
{
    m_map_update.erase(type);
}

void UpdateHandler::_add_upt(string type, shared_ptr<State> st)
{
    m_map_update.insert(pair<string, shared_ptr<State>>(type,st));
}

} // namespace um
