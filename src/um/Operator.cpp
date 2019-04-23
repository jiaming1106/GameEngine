#include <um/Operator.h>
#include <iostream>
using namespace std;
using namespace um;

namespace um{

    Operator::Operator()
    {
        //ctor
    }

    Operator::~Operator()
    {
        //dtor
    }

    Operator::Operator(OperatorHandle oh, unsigned int pl, unsigned int b, um::Position po,std::string name) :
        m_handle(oh),m_player(pl),m_blood(b),m_pos(po),m_name(name)
    {

    }

    int Operator::onUpdate(float dt)
    {
        return 1;
    }


    unsigned int Operator::getPlayer()
    {
        return m_player;
    }

    Position Operator::getPosition()
    {
        return m_pos;
    }

    OperatorHandle Operator::getHandle()
    {
        return m_handle;
    }

    int Operator::getBlood()
    {
        return m_blood;
    }

    int Operator::getType()
    {
        return m_type;
    }


}

