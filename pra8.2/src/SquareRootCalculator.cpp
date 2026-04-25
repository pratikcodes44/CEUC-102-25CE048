#include "SquareRootCalculator.h"
#include <cmath>

// --- NegativeNumberException Implementation ---
NegativeNumberException::NegativeNumberException(const std::string& msg)
{
    message = msg;
}

char* NegativeNumberException::what()
{
    return message.c_str();
}

double SquareRootCalculator::calculate(double number)
{
    if (number < 0)
    {
        throw NegativeNumberException("Error: Cannot calculate the square root of a negative number!");
    }
    return std::sqrt(number);
}
