#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

#include <string>
#include <thread>

#include <um/UpdateEngine.h>
#include <um/Timer.h>
#include <um/Event.h>

using namespace std;

namespace um
{
    class UpdateManager
    {
        public:

            UpdateManager();

            ~UpdateManager();

            void onStart();

            void onPause();

            void onStop();

            void onEvent(const Event ev);

        private:

            void _world_update(float dt);

            void _action_update(Event ev);

        private:

            const float m_fps = 3;

            shared_ptr<UpdateEngine> m_engine;

            Timer m_timer;
    };
}


#endif // UPDATEMANAGER_H
