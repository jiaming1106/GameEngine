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
        UpdateHandler::onUpdate(dt);

        for(auto it : m_com_lists)
        {
            it->onUpdate(dt);
        }

        return 1;
    }

    int Operator::onAction(Action act)
    {
        int ret = 0;
        if(ActionHandler::onAction(act))
            ret = 1;
        for(auto it : m_com_lists)
        {
            if(it->onAction(act))
                ret = 1;
        }
        return ret;
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

    void Operator::setPosition(Position pos)
    {
        m_pos = pos;
    }

    void Operator::setBlood(int blood)
    {
        m_blood = blood;
    }

}

