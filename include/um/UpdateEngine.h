#ifndef UPDATEENGINE_H
#define UPDATEENGINE_H

#include <um/Marco.h>
#include <um/Action.h>
#include <um/Operator.h>
#include <um/GameWorld.h>
#include <string>
#include <memory>
#include <map>

namespace um
{
    class UpdateEngine
    {
        public:

            UpdateEngine(shared_ptr<GameWorld> ww);

            ~UpdateEngine();

            void world_update(float dt);

            void action_update(Action act);

        private:
            bool _insert(OperatorHandle op_h);

            void _del(OperatorHandle op_h);

        private:
            shared_ptr<GameWorld> m_world;

            map<OperatorHandle, shared_ptr<Operator>> m_op_list;
    };
}


#endif // UPDATEENGINE_H
