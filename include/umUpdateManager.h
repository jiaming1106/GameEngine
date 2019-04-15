#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

#include <string>
#include <thread>

#include "umUpdateEngine.h"
#include "umTimer.h"
#include "umAction.h"

using namespace std;

namespace um
{
    class UpdateManager
    {
        public:

            UpdateManager();

            ~UpdateManager();

            void loop_start();

            void loop_pause();

            void loop_stop();

            void update(Action action);

        protected:

        private:

            void _world_update();

            void _action_update(Action action);

        private:

            const int m_fps = 30;

            UpdateEngine m_engine;

            Timer m_timer;
    };
}


#endif // UPDATEMANAGER_H
