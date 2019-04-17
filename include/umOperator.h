#ifndef UMOPERATOR_H
#define UMOPERATOR_H

#include <umAction.h>

namespace um
{
    class Operator
    {
        public:
            Operator();

            virtual ~Operator();

            /**< to response different action */
            virtual void onAction(Action act);
    };
}


#endif // UMOPERATOR_H
