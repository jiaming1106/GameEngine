#include "WeaponComponent.h"
#include <iostream>
#include <functional>
#include <um/Marco.h>

using namespace std;

WeaponComponent::WeaponComponent()
{
    //ctor
}

WeaponComponent::~WeaponComponent()
{
    //dtor
}

WeaponComponent::WeaponComponent(std::shared_ptr<Operator>op) :
    m_op(op)
{
    _bind_act("SHOOT",bind(&WeaponComponent::onShoot,this,placeholders::_1));
}

int WeaponComponent::onUpdate(float dt)
{
    return Component::onUpdate(dt);
}

int WeaponComponent::onShoot(Action& act)
{
    cout<<"Player "<<m_op->getPlayer()<<" OP"<<m_op->getHandle()<<" : ";
    cout<<"Shoot"<<endl;
    return 0;
}
