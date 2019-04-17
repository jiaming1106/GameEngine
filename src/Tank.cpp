#include "Tank.h"
#include <iostream>
using namespace std;
using namespace um;

Tank::Tank()
{
    _bind_act();
}

Tank::~Tank()
{

}

Tank::Tank(unsigned int pl, unsigned int b, um::Position po) :
    m_player(pl),m_blood(b),m_pos(po)
{
    _bind_act();
}

void Tank::_bind_act()
{
    m_map_act.insert(pair<string, function<void(Action&)>>("MOVE",bind(&Tank::onMove,this,placeholders::_1)));
    m_map_act.insert(pair<string, function<void(Action&)>>("SHOOT",bind(&Tank::onShoot,this,placeholders::_1)));
    m_map_act.insert(pair<string, function<void(Action&)>>("INJURY",bind(&Tank::onInjury,this,placeholders::_1)));
}

void Tank::onAction(Action act)
{
    cout<<"Player "<<m_player<<" Tank : ";
    m_map_act[act.type()](act);
    cout<<endl;
}

void Tank::onMove(Action& act)
{
    Position temp = m_pos;
    m_pos += act.arg(1).m_asInt;
    cout<<"Position "<<temp<<"-->"<<m_pos;
}

void Tank::onShoot(Action& act)
{
    cout<<"Shoot";
}

void Tank::onInjury(Action& act)
{
    unsigned int temp = m_blood;
    m_blood -= act.arg(1).m_asInt;
    cout<<"Blood "<<temp<<"-->"<<m_blood;
}

