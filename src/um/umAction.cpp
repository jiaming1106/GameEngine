#include <um/Action.h>

um::Action::Action()
{
    //ctor
}

um::Action::~Action()
{
    //dtor
}

um::Action::Action(const ActionType tt)
{
    m_type = tt;
}


void um::Action::setType(const ActionType tt)
{
    m_type = tt;
}

void um::Action::addArg(const Variant arg)
{
    m_args.push_back(arg);
}


um::ActionType um::Action::type()
{
    return m_type;
}

um::Variant um::Action::arg(int argn)
{
    return m_args.at(argn);
}
