#ifndef UPDATEENGINE_H
#define UPDATEENGINE_H

#include <um/Marco.h>
#include <um/Action.h>
#include <um/Operator.h>
#include <string>
#include <memory>
#include <map>

namespace um
{
    class UpdateEngine
    {
        public:
            UpdateEngine();
            virtual ~UpdateEngine();

            void world_update(float dt);

            void action_update(Action act);

        private:
            bool _insert(OperatorHandle op_h, shared_ptr<Operator> op);

            void _del(OperatorHandle op_h);

        private:
            map<OperatorHandle, shared_ptr<Operator>> m_op_list;

            double m_worldstep;
    };
}


#endif // UPDATEENGINE_H
