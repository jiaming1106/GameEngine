#include <operator/Missile.h>
#include <functional>
#include <iostream>
#include <component/HealthComponent.h>
#include <component/MobilityComponent.h>
#include <component/WeaponComponent.h>

using namespace um;
using namespace std;

Missile::Missile()
{
    _init_com();
}

Missile::~Missile()
{
    //dtor
}

Missile::Missile(OperatorHandle oh, unsigned int pl, um::Position po) :
    Operator(oh,pl,1,po,"Missile")
{
    m_type = 1;
    m_lifetime = 15.0;
    _init_com();
}

void Missile::_init_com()
{
    shared_ptr<Component> com1(new HealthComponent(shared_ptr<Operator>(this)));
    shared_ptr<Component> com2(new MobilityComponent(shared_ptr<Operator>(this)));
    shared_ptr<Component> com3(new WeaponComponent(shared_ptr<Operator>(this)));

    m_com_lists.push_back(com1);
    m_com_lists.push_back(com2);
    m_com_lists.push_back(com3);
}

int Missile::onUpdate(float dt)
{
    m_lifetime -= dt;
    if(m_blood<1 || m_lifetime<0)
    {
        cout<<"\033[32mPlayer "<<m_player<<" "<<m_name<<" : Destroy\033[0m "<<endl;
        return 0;
    }

    Operator::onUpdate(dt);

    if(m_blood<1)
    {
        cout<<"\033[32mPlayer "<<m_player<<" "<<m_name<<" : Destroy\033[0m "<<endl;
        return 0;
    }

    return 1;
}



