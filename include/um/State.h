#ifndef UMSTATE_H
#define UMSTATE_H

#include <functional>

using namespace std;

namespace um
{
    class State
    {
        public:
            State();

            State(function<void(float)> ff, function<int()> ee);

            ~State();

            int update(float dt);

        private:

            function<void(float)> m_func;

            function<int()> m_isEnd;

    };
}


#endif // UMSTATE_H
