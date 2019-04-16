#ifndef UMACTION_H
#define UMACTION_H

#include <functional>
#include <vector>
#include "umMarco.h"

using namespace std;

namespace um
{
    class Action
    {
        public:
            Action();
            virtual ~Action();

        protected:

        private:
            InsTaskList tasks;
    };
}

#endif // UMACTION_H
