#include <iostream>
#include "stack.h"
#include "algorithms.h"
#include "../tests.h"

using namespace std;

int main()
{
    int const MAX = 5;
    // Constructor
    cout << "Create empty stack\n";

    Stack<int, MAX> s1;

    // isEmpty
    cout << "Is stack empty? ";
    startTest("1");
    cout << s1.isEmpty();
    endTest();

    // Push
    cout << "Push into stack 1, 2, 3, 4, 5\n";

    for (int i = 1; i <= MAX; i++)
    {
        s1.push(i);
    }

    // Read
    cout << "Read last element: ";
    startTest("5");
    cout << s1.read();
    endTest();

    // Copy constructor
    cout << "Create copy stack\n";

    Stack<int, MAX> s2(s1);

    cout << "Empty first stack\n";
    while (!s1.isEmpty()) s1.pop();

    cout << "Is second stack still full? ";
    startTest("1");
    cout << (!s2.isEmpty());
    endTest();

    // Pop
    cout << "Pop all: ";
    startTest("5, 4, 3, 2, 1,");
    while (!s2.isEmpty())
    {
        cout << s2.pop() << ", ";
    }
    endTest();

    // Read empty
    cout << "Try to read an element when empty: ";
    startTest("0");
    cout << s2.read();
    endTest();

    // Overpop
    cout << "Try to pop an element when empty: ";
    startTest("0");
    cout << s2.pop();
    endTest();

    // Overpush
    cout << "Try to push more element than maximum(5) [1,2,3,4,5,6]\n";
    for (int i = 1; i <= MAX + 1; i++) s2.push(i);
    cout << "Get last element: ";
    startTest("5");
    cout << s2.read();
    endTest();

    // Palindrome
    cout << "Are acbca, acbbca and acbde palindrome? ";
    startTest("1, 1, 0");
    cout << isPalindrome("acbca") << ", ";
    cout << isPalindrome("acbbca") << ", ";
    cout << isPalindrome("acbde");
    endTest();

    cout << "End\n";
    return 0;
}
