//
// Created by Daniel Pettersen on 2019-10-09.
//

#include "Timer.h"

void Timer::startTimer(int min, int sec) {
    int timerTime = min*60 + sec;

    if (timerTime > 0){
        auto *shared = new Shared();
        auto s = secondFunction;
        auto m = minuteFunction;

        std::thread secondThread(s, shared, timerTime);
        std::thread minuteThread(m, shared);
        secondThread.join();
        minuteThread.join();
    }
}

void Timer::secondFunction(Timer::Shared *pShared, int timeoutTime) {
    int seconds = 0;

    while (!pShared->stopFlag) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds = (seconds + 1) % 60;
        pShared->setSecond(seconds);
        if (seconds == 0) {
            timeoutTime = timeoutTime-60;
            pShared->minuteTick();
        }
        if (seconds < 10) {
            pShared->printTimeSingleDigit();
        } else {
            pShared->printTime();
        }
        if (seconds == timeoutTime) {
            pShared->stopFlag = true;
            pShared->minuteTick();
        }
    }
}

void Timer::minuteFunction(Timer::Shared *pShared) {
    int minutes = 0;
    while (!pShared->stopFlag) {
        pShared->waitForTick();
        minutes++;
        pShared->setMinute(minutes);
    }
}

Timer::Shared::Shared() {
    stopFlag = false;
    minute.lock();
}

void Timer::Shared::minuteTick() {
    minute.unlock();
}

void Timer::Shared::waitForTick() {
    minute.lock();
}

void Timer::Shared::printTime() {
    std::cout << min << ":" << sec << std::endl;
}

void Timer::Shared::printTimeSingleDigit() {
    std::cout << min << ":0" << sec << std::endl;
}

void Timer::Shared::setMinute(int minute) {
    this->min = minute;
}

void Timer::Shared::setSecond(int second) {
    this->sec = second;
}