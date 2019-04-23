#include "um/ActionHandler.h"

namespace um {

ActionHandler::ActionHandler()
{
    //ctor
}

ActionHandler::~ActionHandler()
{
    //dtor
}

int ActionHandler::onAction(Action act)
{
    auto it = m_map_act.find(act.type());
    int ret = 0;
    if(it!=m_map_act.end())
    {
        ret = (it->second)(act);
    }
    return ret;
}

void ActionHandler::_bind_act(ActionType type, ActionFunc func)
{
    /**< TODO : simplify BIND function to MEMBER function */
    //m_map_act.insert(pair<ActionType, ActionFunc>(type,bind(static_cast<pMemFunc> (func),this,placeholders::_1)));
    m_map_act.insert(pair<ActionType, ActionFunc>(type,func));
}

} // namespace um

