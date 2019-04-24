#include <operator/Tank.h>
#include <functional>
#include <iostream>
#include <component/HealthComponent.h>
#include <component/MobilityComponent.h>
#include <component/WeaponComponent.h>

using namespace std;
using namespace um;

Tank::Tank()
{
    _init_com();
}

Tank::~Tank()
{

}

Tank::Tank(OperatorHandle oh, unsigned int pl, unsigned int b, um::Position po) :
    Operator(oh,pl,b,po,"Tank")
{
    m_type = 0;
    _init_com();
}

void Tank::_init_com()
{
    shared_ptr<Component> com1(new HealthComponent(shared_ptr<Operator>(this)));
    shared_ptr<Component> com2(new MobilityComponent(shared_ptr<Operator>(this)));
    shared_ptr<Component> com3(new WeaponComponent(shared_ptr<Operator>(this)));

    m_com_lists.push_back(com1);
    m_com_lists.push_back(com2);
    m_com_lists.push_back(com3);

    _bind_act("LINKOP",bind(&Tank::onLink,this,placeholders::_1));
}

int Tank::onUpdate(float dt)
{
    if(m_blood<1)
    {
        cout<<"\033[32mPlayer "<<m_player<<" "<<m_name<<" : Died\033[0m "<<endl;
        return 0;
    }

    Operator::onUpdate(dt);

    if(m_blood<1)
    {
        cout<<"\033[32mPlayer "<<m_player<<" "<<m_name<<" : Died\033[0m "<<endl;
        return 0;
    }

    return 1;
}

int Tank::onLink(Action& act)
{
    m_link_op.push_back(act.arg(1).m_asHandle);
    return 0;
}



