#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    int const MAX = 5;
    // Constructor
    cout << "Create empty queue\n";

    Queue<int, MAX> q1;

    // isEmpty
    cout << "Is queue empty? " << q1.isEmpty() << "\n";

    // Push
    cout << "Push into queue 1, 2, 3, 4, 5\n";

    for (int i = 1; i <= MAX; i++)
    {
        q1.push(i);
    }

    // Read
    cout << "Read last element: " << q1.read() << "\n";

    // Copy constructor
    cout << "Create copy queue\n";

    Queue<int, MAX> q2(q1);

    cout << "Empty first queue\n";
    while (!q1.isEmpty()) q1.pop();

    cout << "Is second queue still full? " << (!q2.isEmpty()) << "\n";

    // Pop
    cout << "Pop all: ";

    while (!q2.isEmpty())
    {
        cout << q2.pop() << ", ";
    }
    cout << "\n";

    // Read empty
    cout << "Try to read an element when empty: " << q2.read() << "\n";

    // Overpop
    cout << "Try to pop an element when empty: " << q2.pop() << "\n";

    // Overpush
    cout << "Try to push more element than maximum(5) [1,2,3,4,5,6]\n";
    for (int i = 1; i <= MAX + 1; i++) q2.push(i);
    cout << "Get last element: " << q2.read() << "\n";

    cout << "End\n";
    return 0;
}
