#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

#include <string>
#include <thread>
#include "UpdateEngine.h"
#include "umObject.h"
#include "umTimer.h"

using namespace std;
typedef std::string umAction;

class UpdateManager : public umObject
{
    public:

        UpdateManager();

        ~UpdateManager();

        void loop_start();

        void loop_pause();

        void loop_stop();

        void update(umAction action);

    protected:

    private:

        void _world_update();

        void _action_update(umAction action);

    private:

        const int m_fps = 30;

        UpdateEngine m_engine;

        umTimer m_timer;
};

#endif // UPDATEMANAGER_H
