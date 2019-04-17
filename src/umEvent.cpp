#include "umEvent.h"

um::Event::Event()
{
    //ctor
}

um::Event::~Event()
{
    //dtor
}

um::Event::Event(const Action act)
{
    m_act.push_back(act);
}

void um::Event::addAction(const Action act)
{
    m_act.push_back(act);
}

um::Action um::Event::action(int i)
{
    return m_act.at(i);
}

int um::Event::actionNum()
{
    return m_act.size();
}
