#ifndef THREADS_UI_H
#define THREADS_UI_H
#include <ConditionalMacros.h>
#include "InputValidation.h"
#include "Timer.h"

class Ui {
public:
    void initUi();

private:
    int getMinutesFromUser();
    int getSecondsFromUser();
};


#endif //THREADS_UI_H
