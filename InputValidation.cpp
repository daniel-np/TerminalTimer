#include "InputValidation.h"

int InputValidation::validateSeconds() {
    int integerInput = validateInteger();
    while (integerInput > 59 || integerInput < 0) {
        std::cout << "Please input a number between 0-59: ";
        integerInput = validateInteger();
    }
    return integerInput;
}

int InputValidation::validateMinutes() {
    return validateInteger();
}

int InputValidation::validateInteger() {
    int input;
    std::cin >> input;

    while (!std::cin) {
        std::cout << "Wrong type!" << std::endl;
        std::cout << "Please input an integer: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> input;
    }

    return input;
}
