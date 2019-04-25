#include "MobilityComponent.h"
#include <iostream>
#include <functional>
#include <um/Marco.h>

using namespace std;

MobilityComponent::MobilityComponent()
{
    //ctor
}

MobilityComponent::~MobilityComponent()
{
    //dtor
}

MobilityComponent::MobilityComponent(std::shared_ptr<Operator> op) :
    m_op(op)
{
    _bind_act("STOP",bind(&MobilityComponent::onStop,this,placeholders::_1));
    _bind_act("MOVE",bind(&MobilityComponent::onMove,this,placeholders::_1));
    _bind_act("MOVETO",bind(&MobilityComponent::onMoveTo,this,placeholders::_1));
}

int MobilityComponent::onUpdate(float dt)
{
    return Component::onUpdate(dt);
}

int MobilityComponent::onMove(Action& act)
{
    cout<<"Player "<<m_op->getPlayer()<<" OP"<<m_op->getHandle()<<" : ";
    Position temp = m_op->getPosition();
    m_op->setPosition(temp + act.arg(1).data().m_asInt);
    cout<<"Move "<<temp<<"-->"<<m_op->getPosition()<<endl;
    return 0;
}

int MobilityComponent::onMoveTo(Action& act)
{
    cout<<"Player "<<m_op->getPlayer()<<" OP"<<m_op->getHandle()<<" : ";
    m_desti = act.arg(1).data().m_asInt;
    m_v = m_desti > m_op->getPosition() ? 1 : -1;
    shared_ptr<State> mt(new State(bind(&MobilityComponent::onMoving,this,placeholders::_1), bind(&MobilityComponent::isGetP,this)));
    _add_upt("MOVING",mt);
    cout<<"Start Moving "<<endl;
    return 1;
}

int MobilityComponent::onStop(Action& act)
{
    cout<<"Player "<<m_op->getPlayer()<<" OP"<<m_op->getHandle()<<" : ";
    _del_upt("MOVING");
    cout<<"Stop "<<endl;
    return 0;
}

int MobilityComponent::onMoving(float dt)
{
    m_op->setPosition(m_op->getPosition() + dt * m_v);
    return 1;
}

int MobilityComponent::isGetP()
{
    if((m_desti - m_op->getPosition())*m_v <= 0){
        return 1;
    }else{
        return 0;
    }
}
