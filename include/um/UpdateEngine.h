#ifndef UPDATEENGINE_H
#define UPDATEENGINE_H

#include <um/Marco.h>
#include <um/Action.h>
#include <um/Operator.h>
#include <um/GameWorld.h>
#include <string>
#include <memory>
#include <map>

#include <SQLInterface.h>

namespace um
{
    class UpdateEngine
    {
        public:

            UpdateEngine(shared_ptr<GameWorld> ww);

            ~UpdateEngine();

            /**< dt - second */
            void world_update(float dt);

            void action_update(Action act);

        private:
            shared_ptr<GameWorld> m_world;

            SQLInterface db;
    };
}


#endif // UPDATEENGINE_H
