#ifndef UM_ACTIONHANDLER_H
#define UM_ACTIONHANDLER_H

#include <um/Action.h>
#include <um/Marco.h>
#include <functional>
#include <string>
#include <map>

using namespace std;

namespace um {

class ActionHandler
{
    //typedef int (ActionHandler::*pMemFunc)(Action& act);

    public:
        ActionHandler();

        ~ActionHandler();

        /** \brief to response different action
         *
         * \param
         * \param
         * \return 1 - need to be update
         *         0 - just instantaneous action
         */
        int onAction(Action act);

    protected:
        /** \brief to bind a action function
         *
         * \param string
         * \param member function
         *
         */
        void _bind_act(ActionType type, ActionFunc func);

    protected:

        map<ActionType, ActionFunc> m_map_act;

};

} // namespace um

#endif // UM_ACTIONHANDLER_H
