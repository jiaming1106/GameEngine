#ifndef UM_EVENTSENDER_H
#define UM_EVENTSENDER_H

#include <um/Event.h>
#include <um/Marco.h>
#include <functional>
#include <string>

namespace um {

class EventSender
{
    public:
        EventSender();
        virtual ~EventSender();

        void associate(function<void(Event)> func);

    protected:

        void _sendEvent(Event act);

    private:
        function<void(Event)> m_EventFunc;
};

} // namespace um

#endif // UM_ACTIONSENDER_H
