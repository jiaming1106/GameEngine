#ifndef UMEVENT_H
#define UMEVENT_H

#include <umMarco.h>
#include <vector>
using namespace std;

namespace um
{
    class Event
    {
        public:
            Event();
            virtual ~Event();

        public:
            /**< TODO : Change the class of type to int supported by DB */
            EventType m_type;
            vector<Variant> m_args;
    };
}


#endif // UMEVENT_H
