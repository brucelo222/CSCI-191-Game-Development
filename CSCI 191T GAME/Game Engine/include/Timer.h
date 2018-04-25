#ifndef TIMER_H
#define TIMER_H

#include <time.h>

class Timer
{
    public:
        Timer();
        virtual ~Timer();

        clock_t startedAt;
        clock_t pausedAt;

        bool started;
        bool paused;

        bool isStarted();
        bool isStopped();
        bool isPaused();

        void pause();
        void resume();
        void start();
        void stop();

        void reset();
        clock_t getTicks();

    private:
};

#endif // TIMER_H
