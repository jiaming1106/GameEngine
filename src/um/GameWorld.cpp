#include "um/GameWorld.h"

#include <um/Event.h>
#include <operator/Tank.h>
#include <operator/Missile.h>
#include <iostream>
#include <SQLInterface.h>

using namespace std;
namespace um {

GameWorld::GameWorld()
{
    //ctor
    _incre = 0;
    _init();
}

GameWorld::~GameWorld()
{
    //dtor
}

void GameWorld::_init()
{
    SQLInterface db;
    db.clear_operator();
    shared_ptr<Tank> t1(new Tank(_newOpHandle(),0,3,10));
    shared_ptr<Tank> t2(new Tank(_newOpHandle(),1,3,40));

    activate(_insert(t1));
    activate(_insert(t2));

    db.add_operator(t1);
    db.add_operator(t2);

    _bind_act("MISSILE",bind(&GameWorld::onMissile,this,placeholders::_1));
}

int GameWorld::OperatorNum()
{
    return m_op_list.size();
}

OperatorHandle GameWorld::_newOpHandle()
{
    /**< can be just like the map we have in our engine
    OR any type of map. NOT SAFE NOW*/
    return _incre++;
}

OperatorHandle GameWorld::_insert(shared_ptr<Operator> op)
{
    auto ret = m_op_list.insert(pair<OperatorHandle,shared_ptr<Operator>>(op->getHandle(),op));
    if(ret.second)
        return op->getHandle();
    else
        return -1;
}

int GameWorld::onMissile(Action& act)
{
    shared_ptr<Operator> tp = m_op_list[act.arg(1).data().m_asHandle];  //not safe

    /**<  create & add a missile */
    shared_ptr<Missile> m1(new Missile(_newOpHandle(),tp->getPlayer(),tp->getPosition()));
    OperatorHandle mi_h = _insert(m1);
    cout<<"GameWorld : add A Missile - "<<mi_h<<endl;
    /**< BAD CODE */
    SQLInterface db;
    db.add_operator(m1);

    /**< gen action of binding missile */
    Action bact(ActionType("LINKOP"));
    um::Variant arg1(um::Variant::TYPE_HANDLE);
    arg1.SetData(act.arg(1).data().m_asHandle);
    bact.addArg(arg1);
    um::Variant arg2(um::Variant::TYPE_HANDLE);
    arg2.SetData(mi_h);
    bact.addArg(arg2);
    /**< and bind it to the tank that launch it */
    tp->onAction(bact);

    /**< activate the missile */
    activate(mi_h);

    return 0;
}

OpList::iterator GameWorld::find(OperatorHandle op_h)
{
    //m_op_list
    return m_update_list.find(op_h);
}

OpList::iterator GameWorld::end()
{
    return m_update_list.end();
}

shared_ptr<Operator> GameWorld::operator[](OperatorHandle op_h)
{
    return m_op_list[op_h];
}

void GameWorld::activate(OperatorHandle op_h)
{
    m_update_list.insert(pair<OperatorHandle, shared_ptr<Operator>>(op_h,m_op_list[op_h]));
}

void GameWorld::inactivate(OperatorHandle op_h)
{
    m_update_list.erase(op_h);
}

void GameWorld::_del(OperatorHandle op_h)
{
    m_op_list.erase(op_h);
}

OpList::iterator GameWorld::update_list_begin()
{
    return m_update_list.begin();
}

OpList::iterator GameWorld::update_list_end()
{
    return m_update_list.end();
}

} // namespace um

