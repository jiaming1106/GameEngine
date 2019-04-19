#ifndef UMOPERATOR_H
#define UMOPERATOR_H

#include <um/Action.h>

namespace um
{
    class Operator
    {
        public:
            Operator();

            virtual ~Operator();

            /**< to response different action */
            virtual void onAction(Action act);

            /**< to response World Update */
            virtual int onUpdate(float dt);
    };
}


#endif // UMOPERATOR_H
