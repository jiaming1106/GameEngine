#ifndef UMDECISION_H
#define UMDECISION_H

#include <string>
#include <vector>
#include "umEvent.h"
#include "umMarco.h"

namespace um
{
    class Decision
    {
        public:

            Decision();

            Decision(UsrInput input);

            void setCommand(UsrInput);

            virtual ~Decision();

            /** \brief Prepare for exec when check
             *
             * \return
             *
             */
            virtual bool check() = 0;

            /** \brief Generate the action list for engine when exec
             *
             * \param
             * \return
             *
             */
            virtual Event genEvent() = 0;

            UsrInput command();
        protected:
            UsrInput m_command;
    };
}


#endif // UMDECISION_H
