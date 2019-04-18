#ifndef UMACTION_H
#define UMACTION_H

#include <vector>
#include <um/Marco.h>

using namespace std;

namespace um
{
    /**< the message Engine send to Object */
    class Action
    {
        public:
            Action();

            Action(const ActionType tt);

            ~Action();

        public:
            void setType(const ActionType tt);

            void addArg(const Variant arg);

            ActionType type();

            Variant arg(int argn);
        private:
            ActionType m_type;
            vector<Variant> m_args;

    };
}

#endif // UMACTION_H
