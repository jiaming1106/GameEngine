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

            /** \brief to response different action
             *
             * \param
             * \param
             * \return 1 - need to be update
             *         0 - just instantaneous action
             */
            virtual int onAction(Action act);

            /** \brief to response World Update
             *
             * \param
             * \param
             * \return 1 - still need update
             *         0 - died
             */
            virtual int onUpdate(float dt);
    };
}


#endif // UMOPERATOR_H
