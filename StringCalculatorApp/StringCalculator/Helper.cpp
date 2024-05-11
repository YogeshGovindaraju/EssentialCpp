#include "Helper.h"

void checkForNegatives(const vector<int>& numbers)
{
    string negatives = for_each(numbers.begin(), numbers.end(), Negatives());

    if (negatives.size() > 0) {
        throw invalid_argument("Negatives not allowed: " + negatives);
    }
}

void addIfValid(vector<int>& numbers, string number_string)
{
    int number = stoi(number_string);
    if (number <= 1000)
        numbers.push_back(number);
}

vector<int> getNumbers(const string& input)
{
    regex numbers_only("(-?\\d+)+");

    vector<int> numbers;
    for_each(sregex_token_iterator(input.begin(), input.end(), numbers_only),
        sregex_token_iterator(),
        [&numbers](string s) { addIfValid(numbers, s); });

    return numbers;
}