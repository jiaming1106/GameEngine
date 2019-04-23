#ifndef UM_GAMEWORLD_H
#define UM_GAMEWORLD_H

#include <um/ActionHandler.h>
#include <um/EventSender.h>
#include <um/Marco.h>
#include <um/Operator.h>
#include <um/Action.h>
#include <memory>
#include <map>


namespace um {
typedef map<OperatorHandle, shared_ptr<Operator>> OpList;

class GameWorld : public ActionHandler,public EventSender
{

    public:
        GameWorld();
        ~GameWorld();

        shared_ptr<Operator> operator[](OperatorHandle op_h);

        void activate(OperatorHandle op_h);

        void inactivate(OperatorHandle op_h);

        int OperatorNum();

    public:
        OpList::iterator find(OperatorHandle op_h);

        OpList::iterator end();

        OpList::iterator update_list_begin();

        OpList::iterator update_list_end();

    private:
        void _init();

        OperatorHandle _insert(shared_ptr<Operator> op);

        void _del(OperatorHandle op_h);

        OperatorHandle _newOpHandle();

        int _incre;

    private:

        OpList m_op_list;

        OpList m_update_list;

    private:
        int onMissile(Action& act);
};

} // namespace um

#endif // UM_GAMEWORLD_H
