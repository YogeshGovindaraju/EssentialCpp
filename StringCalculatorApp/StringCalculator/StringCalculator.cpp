#include "StringCalculator.h"

int StringCalculator::add(string input)
{
    if (input.empty())
        return 0;

    vector<int> numbers = getNumbers(input);

    checkForNegatives(numbers);

    return accumulate(numbers.begin(), numbers.end(), 0);
}
