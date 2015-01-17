#include <iostream>

using namespace std;

void startTest(string it)
{
    cout << "\n(it should be \"" << it << "\"): \033[1;31m";
}

void endTest()
{
    cout << "\033[0m\n\n";
}
