#ifndef UMDECISION_H
#define UMDECISION_H

#include <string>
#include <vector>
#include "umAction.h"
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
            virtual void genAction(vector<Action> &act_list) = 0;

        protected:

        private:
            UsrInput m_command;
    };
}


#endif // UMDECISION_H
