#ifndef UMTIMER_H
#define UMTIMER_H

#include <functional>
#include <thread>

using namespace std;

namespace um
{
    class Timer
    {
        public:

            Timer();

            ~Timer();

            void SetTimer(int interval, std::function<void()> func);

            void Start();

            void Pause();

            void Stop();

        private:

            void _run_task();

        protected:

        private:

            bool run;

            std::function<void()> task;

            int delta;
    };
}


#endif // UMTIMER_H
