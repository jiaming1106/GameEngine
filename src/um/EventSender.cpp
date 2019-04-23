#include "um/EventSender.h"

namespace um {

EventSender::EventSender()
{
    //ctor
}

EventSender::~EventSender()
{
    //dtor
}

void EventSender::associate(function<void(Event)>func)
{
    m_EventFunc = func;
}

void EventSender::_sendEvent(Event evt)
{
    m_EventFunc(evt);
}

} // namespace um
