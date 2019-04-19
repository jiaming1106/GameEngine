#ifndef UM_GAMEWORLD_H
#define UM_GAMEWORLD_H

#include <um/Marco.h>
#include <um/Operator.h>
#include <memory>
#include <map>

namespace um {
typedef map<OperatorHandle, shared_ptr<Operator>> OpMap;

/**< maybe  inherit from std::map*/
class GameWorld
{

    public:
        GameWorld();
        ~GameWorld();

        shared_ptr<Operator> operator[](OperatorHandle op_h);

        OpMap::iterator find(OperatorHandle op_h);

        OpMap::iterator end();

    private:
        void _init();

        bool _insert(OperatorHandle op_h, shared_ptr<Operator> op);

        void _del(OperatorHandle op_h);

    private:
        OpMap m_op_list;
};

} // namespace um

#endif // UM_GAMEWORLD_H
