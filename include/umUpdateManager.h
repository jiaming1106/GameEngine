#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

#include <string>
#include <thread>

#include "umUpdateEngine.h"
#include "umTimer.h"
#include "umEvent.h"

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

            void _world_update();

            void _action_update(Event ev);

        private:

            const int m_fps = 30;

            UpdateEngine m_engine;

            Timer m_timer;
    };
}


#endif // UPDATEMANAGER_H
