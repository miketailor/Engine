#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <Windows.h>


namespace mk {

 class Timer
        {
    private:
        LARGE_INTEGER start;

    public:
        Timer()
        {
                    QueryPerformanceCounter(start);
        }

        };

}

#endif // TIMER_H_INCLUDED
