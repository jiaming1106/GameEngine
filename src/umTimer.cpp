#include "umTimer.h"
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

um::Timer::Timer()
{
    //ctor
    run = false;
}

um::Timer::~Timer()
{
    //dtor
}

void um::Timer::SetTimer(int interval, std::function<void()>func)
{
    task = func;
    delta = interval;
}

void um::Timer::Start()
{
    run = true;
    _run_task();
}

void um::Timer::_run_task()
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

void um::Timer::Pause()
{
    run = false;
    //TODO :: get the second and continue to the right second
}

void um::Timer::Stop()
{
    run = false;
}
