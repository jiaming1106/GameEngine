#include <operator/Missile.h>
#include <functional>
#include <iostream>

using namespace um;
using namespace std;
using namespace std::placeholders;

Missile::Missile()
{
    _init_bind();
}

Missile::~Missile()
{
    //dtor
}

Missile::Missile(OperatorHandle oh, unsigned int pl, um::Position po) :
    Operator(oh,pl,1,po,"Missile")
{
    m_type = 1;
    _init_bind();
    m_lifetime = 10.0;
}

void Missile::_init_bind()
{
    _bind_act("STOP",bind(&Missile::onStop,this,_1));
    _bind_act("MOVE",bind(&Missile::onMove,this,_1));
    _bind_act("SHOOT",bind(&Missile::onShoot,this,_1));
    _bind_act("INJURY",bind(&Missile::onInjury,this,_1));
    _bind_act("MOVETO",bind(&Missile::onMoveTo,this,_1));
    _bind_act("DESTROY",bind(&Missile::onDestroy,this,_1));
}

int Missile::onUpdate(float dt)
{
    m_lifetime -= dt;
    if(m_blood<1 || m_lifetime<0)
    {
        cout<<"\033[32mPlayer "<<m_player<<" "<<m_name<<" : Destroy\033[0m "<<endl;
        return 0;
    }

    vector<string> end_state;
    for(auto it : m_map_update)
    {
        //cout<<"\033[32m";
        //cout<<"Player "<<m_player<<" "<<m_name<<" : ";
        int ans = (it.second)->update(dt);
        if(ans == 1 ) end_state.push_back(it.first);
        //cout<<"\033[0m"<<endl;
    }
    /**< delete the  sustained action WHEN it finished*/
    for(auto et : end_state)
    {
        m_map_update.erase(et);
    }

    if(m_blood<1)
    {
        cout<<"\033[32mPlayer "<<m_player<<" "<<m_name<<" : Destroy\033[0m "<<endl;
        return 0;
    }

    return 1;
}

int Missile::onMove(Action& act)
{
    cout<<"Player "<<m_player<<" "<<m_name<<" : ";
    Position temp = m_pos;
    m_pos += act.arg(1).m_asInt;
    cout<<"Move "<<temp<<"-->"<<m_pos<<endl;
    return 0;
}

int Missile::onMoveTo(Action& act)
{
    cout<<"Player "<<m_player<<" "<<m_name<<" : ";
    m_desti = act.arg(1).m_asInt;
    m_v = m_desti > m_pos ? 1 : -1;
    shared_ptr<State> mt(new State(bind(&Missile::onMoving,this,placeholders::_1), bind(&Missile::isGetP,this)));
    m_map_update.insert(pair<string, shared_ptr<State>>("MOVING",mt));
    cout<<"Start Moving "<<endl;
    return 1;
}

int Missile::onShoot(Action& act)
{
    cout<<"Player "<<m_player<<" "<<m_name<<" : ";
    cout<<"Shoot";
    m_blood = 0;
    cout <<" & Missile Destroy";
    cout<<endl;
    return 0;
}

int Missile::onInjury(Action& act)
{
    cout<<"Player "<<m_player<<" "<<m_name<<" : ";
    unsigned int temp = m_blood;
    m_blood -= act.arg(1).m_asInt;
    cout<<"Injury "<<temp<<"-->"<<m_blood;
    /**< TODO : blood < 1 should be del immediately or
    died tank can shoot or move if send the Decision quickly*/
    if(m_blood < 1)
        cout <<" Died";
    cout<<endl;
    return 0;
}

int Missile::onMoving(float dt)
{
    //Position temp = m_pos;
    m_pos += dt * m_v;
    //cout<<"Moving "<<temp<<"-->"<<m_pos;
    return 1;
}

int Missile::onStop(Action& act)
{
    cout<<"Player "<<m_player<<" "<<m_name<<" : ";
    m_map_update.erase("MOVING");
    cout<<"Stop "<<endl;
    return 0;
}

int Missile::isGetP()
{
    if((m_desti - m_pos)*m_v <= 0){
        return 1;
    }else{
        return 0;
    }
}

int Missile::onDestroy(Action& act)
{
    m_blood = 0;
    return 0;
}


