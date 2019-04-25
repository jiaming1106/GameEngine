#include <decision/StopDecision.h>
#include <sstream>

StopDecision::StopDecision()
{
    //ctor
}

StopDecision::~StopDecision()
{
    //dtor
}


bool StopDecision::check()
{
    /**< this parse should be in the base to ensure bing done */
    if(_parse())
        return true;
    else
        return false;
}

Event StopDecision::genEvent()
{
    Action act1(ActionType("STOP"));
    um::Variant arg1(um::Variant::TYPE_HANDLE);
    arg1.SetData(m_stop_bop);
    act1.addArg(arg1);

    Event stop_ev(act1);

    return stop_ev;
}

bool StopDecision::_parse()
{
    stringstream ss(m_command);
    string buf;
    /**< DANGEROUS */
    ss>>buf;
    ss>>m_stop_bop;
    return true;
}
