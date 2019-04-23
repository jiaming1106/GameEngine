#include <operator/Tank.h>
#include <functional>
#include <iostream>

using namespace std;
using namespace um;
using namespace std::placeholders;

Tank::Tank()
{
    _init_bind();
}

Tank::~Tank()
{

}

Tank::Tank(OperatorHandle oh, unsigned int pl, unsigned int b, um::Position po) :
    Operator(oh,pl,b,po,"Tank")
{
    m_type = 0;
    _init_bind();
}

void Tank::_init_bind()
{
    _bind_act("STOP",bind(&Tank::onStop,this,_1));
    _bind_act("MOVE",bind(&Tank::onMove,this,_1));
    _bind_act("SHOOT",bind(&Tank::onShoot,this,_1));
    _bind_act("INJURY",bind(&Tank::onInjury,this,_1));
    _bind_act("MOVETO",bind(&Tank::onMoveTo,this,_1));
    _bind_act("LINKOP",bind(&Tank::onLink,this,_1));
}

/**< can be write in the BASE Class */
int Tank::onUpdate(float dt)
{
    if(m_blood<1)
    {
        cout<<"\033[32mPlayer "<<m_player<<" "<<m_name<<" : Died\033[0m "<<endl;
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
        cout<<"\033[32mPlayer "<<m_player<<" "<<m_name<<" : Died\033[0m "<<endl;
        return 0;
    }

    return 1;
}

int Tank::onMove(Action& act)
{
    cout<<"Player "<<m_player<<" "<<m_name<<" : ";
    Position temp = m_pos;
    m_pos += act.arg(1).m_asInt;
    cout<<"Move "<<temp<<"-->"<<m_pos<<endl;
    return 0;
}

int Tank::onMoveTo(Action& act)
{
    cout<<"Player "<<m_player<<" "<<m_name<<" : ";
    m_desti = act.arg(1).m_asInt;
    m_v = m_desti > m_pos ? 1 : -1;
    shared_ptr<State> mt(new State(bind(&Tank::onMoving,this,placeholders::_1), bind(&Tank::isGetP,this)));
    m_map_update.insert(pair<string, shared_ptr<State>>("MOVING",mt));
    cout<<"Start Moving "<<endl;
    return 1;
}

int Tank::onShoot(Action& act)
{
    cout<<"Player "<<m_player<<" "<<m_name<<" : ";
    cout<<"Shoot"<<endl;
    return 0;
}

int Tank::onInjury(Action& act)
{
    cout<<"Player "<<m_player<<" "<<m_name<<" : ";
    unsigned int temp = m_blood;
    m_blood -= act.arg(1).m_asInt;
    cout<<"Injury "<<temp<<"-->"<<m_blood;
    /**< TODO : blood < 1 should be del immediately or
    died tank can shoot or move if send the Decision quickly*/
    if(m_blood < 1){
        if(!m_link_op.empty())
        {
            /**< gen a event of destroy p */
            Event des_ev;
            for(auto it : m_link_op)
            {
                Action act1(ActionType("DESTROY"));
                um::Variant arg1(um::Variant::TYPE_HANDLE);
                arg1.m_asHandle = it;
                act1.addArg(arg1);
                des_ev.addAction(act1);
            }
            _sendEvent(des_ev);
        }
    }
    cout<<endl;
    return 0;
}

int Tank::onMoving(float dt)
{
    //Position temp = m_pos;
    m_pos += dt * m_v;
    //cout<<"Moving "<<temp<<"-->"<<m_pos;
    return 1;
}

int Tank::onStop(Action& act)
{
    cout<<"Player "<<m_player<<" "<<m_name<<" : ";
    m_map_update.erase("MOVING");
    cout<<"Stop "<<endl;
    return 0;
}

int Tank::isGetP()
{
    if((m_desti - m_pos)*m_v <= 0){
        return 1;
    }else{
        return 0;
    }
}


int Tank::onLink(Action& act)
{
    m_link_op.push_back(act.arg(1).m_asHandle);
    return 0;
}



