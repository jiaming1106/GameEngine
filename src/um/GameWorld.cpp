#include "um/GameWorld.h"

#include <operator/Tank.h>

namespace um {

GameWorld::GameWorld()
{
    //ctor
    _init();
}

GameWorld::~GameWorld()
{
    //dtor
}

OpMap::iterator GameWorld::find(OperatorHandle op_h)
{
    return m_op_list.find(op_h);
}

OpMap::iterator GameWorld::end()
{
    return m_op_list.end();
}


shared_ptr<Operator> GameWorld::operator[](OperatorHandle op_h)
{
    return m_op_list[op_h];
}

void GameWorld::_init()
{
    shared_ptr<Tank> t1(new Tank(0,3,0));
    shared_ptr<Tank> t2(new Tank(1,3,10));
    _insert(0,t1);
    _insert(1,t2);
}

bool GameWorld::_insert(OperatorHandle op_h, shared_ptr<Operator>op)
{
    auto ret = m_op_list.insert(pair<OperatorHandle,shared_ptr<Operator>>(op_h,op));
    return ret.second;
}

void GameWorld::_del(OperatorHandle op_h)
{
    m_op_list.erase(op_h);
}


} // namespace um

