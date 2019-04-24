#include "HealthComponent.h"
#include <iostream>
#include <functional>
#include <um/Marco.h>

using namespace std;

HealthComponent::HealthComponent()
{
    //ctor
}

HealthComponent::HealthComponent(std::shared_ptr<Operator>op) :
    m_op(op)
{
    _bind_act("INJURY",bind(&HealthComponent::onInjury,this,placeholders::_1));
    _bind_act("DESTROY",bind(&HealthComponent::onDestroy,this,placeholders::_1));
}

HealthComponent::~HealthComponent()
{
    //dtor
}

int HealthComponent::onUpdate(float dt)
{
    return Component::onUpdate(dt);
}

int HealthComponent::onInjury(Action& act)
{
    cout<<"Player "<<m_op->getPlayer()<<" OP"<<m_op->getHandle()<<" : ";
    unsigned int temp = m_op->getBlood();
    m_op->setBlood(temp-act.arg(1).m_asInt);
    cout<<"Injury "<<temp<<"-->"<<m_op->getBlood();
    /**< TODO : blood < 1 should be del immediately or
    died tank can shoot or move if send the Decision quickly*/
    cout<<endl;
    return 0;
}

int HealthComponent::onDestroy(Action& act)
{
    m_op->setBlood(0);
    return 0;
}
