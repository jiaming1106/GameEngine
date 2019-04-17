#ifndef UMEVENT_H
#define UMEVENT_H

#include <umMarco.h>
#include <umAction.h>
#include <vector>
using namespace std;

namespace um
{
    /**< the message Decision send to Engine */
    class Event
    {
        public:
            Event();
            Event(const Action act);
            ~Event();

        public:
            void addAction(const Action act);

            Action action(int i);

            int actionNum();

        private:
            vector<Action> m_act;
    };
}


#endif // UMEVENT_H
