#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include "Negatives.h"

using namespace std;

void checkForNegatives(const vector<int>& numbers);
void addIfValid(vector<int>& numbers, string number_string);
vector<int> getNumbers(const string& input);