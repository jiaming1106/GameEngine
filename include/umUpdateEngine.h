#ifndef UPDATEENGINE_H
#define UPDATEENGINE_H

#include <string>
#include <umAction.h>

namespace um
{
    class UpdateEngine
    {
        public:
            UpdateEngine();
            virtual ~UpdateEngine();

            void world_update();

            void action_update(Action action);

        protected:

        private:
            double m_worldstep;
    };
}


#endif // UPDATEENGINE_H
