#include "Ui.h"

void Ui::initUi() {

    int min = getMinutesFromUser();
    int sec = getSecondsFromUser();
    if (sec < 10){
        std::cout << "Timer set for: " << min << ":0" << sec << std::endl;
    } else {
        std::cout << "Timer set for: " << min << ":" << sec << std::endl;
    }

    if (TARGET_OS_MAC == 1) {
        std::cout << "Press any key to continue..." << std::endl;
        system("read");
    } else {
        system("pause");
    }
    Timer::startTimer(min, sec);
}

int Ui::getMinutesFromUser() {
    std::cout << "Set minutes: ";
    int minutes = InputValidation().validateMinutes();
    return minutes;
}

int Ui::getSecondsFromUser() {
    std::cout << "Set seconds: ";
    int seconds = InputValidation().validateSeconds();
    return seconds;
}