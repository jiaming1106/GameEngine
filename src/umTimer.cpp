#include "umTimer.h"
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

umTimer::umTimer()
{
    //ctor
    run = false;
}

umTimer::~umTimer()
{
    //dtor
}

void umTimer::SetTimer(int interval, std::function<void()>func)
{
    task = func;
    delta = interval;
}

void umTimer::Start()
{
    run = true;
    _run_task();
}

void umTimer::_run_task()
{
    std::thread t1([this](){
                    std::this_thread::sleep_for(std::chrono::milliseconds(this->delta));
                    if(this->run)
                        this->task();
                    if(this->run)
                        this->_run_task();
                });
    if(run) t1.detach();
}

void umTimer::Pause()
{
    run = false;
    //TODO :: get the second and continue to the right second
}

void umTimer::Stop()
{
    run = false;
}
