#include <operator/Tank.h>
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

/**< can be write in the BASE Class, but this BAND may need more template to achieve a better one*/
/**< Can be simplify */
void Tank::_bind_act()
{
    m_map_act.insert(pair<string, function<void(Action&)>>("STOP",bind(&Tank::onStop,this,placeholders::_1)));
    m_map_act.insert(pair<string, function<void(Action&)>>("MOVE",bind(&Tank::onMove,this,placeholders::_1)));
    m_map_act.insert(pair<string, function<void(Action&)>>("SHOOT",bind(&Tank::onShoot,this,placeholders::_1)));
    m_map_act.insert(pair<string, function<void(Action&)>>("INJURY",bind(&Tank::onInjury,this,placeholders::_1)));
    m_map_act.insert(pair<string, function<void(Action&)>>("MOVETO",bind(&Tank::onMoveTo,this,placeholders::_1)));
}

/**< can be write in the BASE Class */
void Tank::onAction(Action act)
{
    cout<<"Player "<<m_player<<" Tank : ";
    m_map_act[act.type()](act);
    cout<<endl;
}

/**< can be write in the BASE Class */
int Tank::onUpdate(float dt)
{
    if(m_blood<1) return 0;
    vector<string> end_state;
    for(auto it : m_map_update)
    {
        cout<<"Player "<<m_player<<" Tank : ";
        int ans = (it.second)->update(dt);
        if(ans == 1 ) end_state.push_back(it.first);
        cout<<endl;
    }
    /**< delete the  sustained action WHEN it finished*/
    for(auto et : end_state)
    {
        m_map_update.erase(et);
    }
    if(m_blood<1) return 0;
    return 1;
}

void Tank::onMove(Action& act)
{
    Position temp = m_pos;
    m_pos += act.arg(1).m_asInt;
    cout<<"Move "<<temp<<"-->"<<m_pos;
}

void Tank::onMoveTo(Action& act)
{
    m_desti = act.arg(1).m_asInt;
    m_v = m_desti > m_pos ? 0.25 : -0.25;
    shared_ptr<State> mt(new State(bind(&Tank::onMoving,this,placeholders::_1), bind(&Tank::isGetP,this)));
    m_map_update.insert(pair<string, shared_ptr<State>>("MOVING",mt));
    cout<<"Start Moving ";
}

void Tank::onShoot(Action& act)
{
    cout<<"Shoot";
}

void Tank::onInjury(Action& act)
{
    unsigned int temp = m_blood;
    m_blood -= act.arg(1).m_asInt;
    cout<<"Injury "<<temp<<"-->"<<m_blood;
    /**< TODO : blood < 1 should be del immediately or
    died tank can shoot or move if send the Decision quickly*/
    if(m_blood < 1)
        cout <<" Died";
}

void Tank::onMoving(float dt)
{
    Position temp = m_pos;
    m_pos += dt * m_v;
    cout<<"Moving "<<temp<<"-->"<<m_pos;
}

void Tank::onStop(Action& act)
{
    m_map_update.erase("MOVING");
    cout<<"Stop ";
}

int Tank::isGetP()
{
    if((m_desti - m_pos)*m_v <= 0){
        return 1;
    }else{
        return 0;
    }
}




