#ifndef UPDATEENGINE_H
#define UPDATEENGINE_H

#include <string>
#include <memory>
#include <vector>
#include "umAction.h"
#include "umOperator.h"

namespace um
{
    class UpdateEngine
    {
        public:
            UpdateEngine();
            virtual ~UpdateEngine();

            void world_update();

            void action_update(Action act);

        protected:

        private:
            vector<shared_ptr<Operator>> m_op_list;
            double m_worldstep;
    };
}


#endif // UPDATEENGINE_H
