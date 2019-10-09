#ifndef THREADS_INPUTVALIDATION_H
#define THREADS_INPUTVALIDATION_H
#include <iostream>

class InputValidation {
public:
    int validateSeconds();
    int validateMinutes();
private:
    int validateInteger();
};


#endif //THREADS_INPUTVALIDATION_H
