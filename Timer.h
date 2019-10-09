//
// Created by Daniel Pettersen on 2019-10-09.
//

#ifndef THREADS_TIMER_H
#define THREADS_TIMER_H

#include <iostream>
#include <thread>

class Timer {

public:
    static void startTimer(int min, int sec);

private:
    class Shared {
    public:
        Shared();
        std::atomic<bool> stopFlag;
        void minuteTick();

        void waitForTick();

        void printTime();

        void printTimeSingleDigit();

        void setMinute(int minute);

        void setSecond(int second);

    private:
        std::mutex minute;
        std::atomic<int> min;
        std::atomic<int> sec;

    };

    static void secondFunction(Timer::Shared *pShared, int timerTime);

    static void minuteFunction(Timer::Shared *pShared);


};


#endif //THREADS_TIMER_H
