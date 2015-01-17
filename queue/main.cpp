#include <iostream>
#include "queue.h"
#include "../tests.h"

using namespace std;

int main()
{
    int const MAX = 5;

    // Constructor
    cout << "Create empty queue\n";

    Queue<int, MAX> q1;

    // isEmpty
    cout << "Is queue empty? ";
    startTest("1");
    cout << q1.isEmpty();
    endTest();

    // Push
    cout << "Push into queue 1, 2, 3, 4, 5\n";

    for (int i = 1; i <= MAX; i++)
    {
        q1.push(i);
    }

    // Read
    cout << "Read first element: ";
    startTest("1");
    cout << q1.read();
    endTest();

    // Copy constructor
    cout << "Create copy queue\n";

    Queue<int, MAX> q2(q1);

    cout << "Empty first queue\n";
    while (!q1.isEmpty()) q1.pop();

    cout << "Is second queue still full? ";
    startTest("1");
    cout << (!q2.isEmpty());
    endTest();

    // Pop
    cout << "Pop all: ";

    startTest("1, 2, 3, 4, 5,");
    while (!q2.isEmpty())
    {
        cout << q2.pop() << ", ";
    }
    endTest();

    // Read empty
    cout << "Try to read an element when empty: ";
    startTest("0");
    cout << q2.read();
    endTest();

    // Overpop
    cout << "Try to pop an element when empty: ";
    startTest("0");
    cout << q2.pop();
    endTest();

    // Overpush
    cout << "Try to push more element than maximum(5) [1,2,3,4,5,6]\n";
    for (int i = 1; i <= MAX + 1; i++) q2.push(i);
    cout << "Get first element: ";
    startTest("1");
    cout << q2.read();
    endTest();
    cout << "Push all: ";
    startTest("1, 2, 3, 4, 5,");
    while (!q2.isEmpty()) cout << q2.pop() << ", ";
    endTest();

    cout << "End\n";
    return 0;
}
