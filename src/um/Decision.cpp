#include <um/Decision.h>

using namespace um;

um::Decision::Decision()
{
}

um::Decision::~Decision()
{
    //dtor
}

um::Decision::Decision(UsrInput input)
{
    m_command = input;
}

void um::Decision::setCommand(UsrInput in)
{
    m_command = in;
}

um::UsrInput um::Decision::command()
{
    return m_command;
}
