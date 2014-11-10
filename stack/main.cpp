#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    int const MAX = 5;
    // Constructor
    cout << "Create empty stack\n";

    Stack<int, MAX> s1;

    // isEmpty
    cout << "Is stack empty? " << s1.isEmpty() << "\n";

    // Push
    cout << "Push into stack 1, 2, 3, 4, 5\n";

    for (int i = 1; i <= MAX; i++)
    {
        s1.push(i);
    }

    // Read
    cout << "Read last element: " << s1.read() << "\n";

    // Copy constructor
    cout << "Create copy stack\n";

    Stack<int, MAX> s2(s1);

    cout << "Empty first stack\n";
    while (!s1.isEmpty()) s1.pop();

    cout << "Is second stack still full? " << (!s2.isEmpty()) << "\n";

    // Pop
    cout << "Pop all: ";

    while (!s2.isEmpty())
    {
        cout << s2.pop() << ", ";
    }
    cout << "\n";

    // Read empty
    cout << "Try to read an element when empty: " << s2.read() << "\n";

    // Overpop
    cout << "Try to pop an element when empty: " << s2.pop() << "\n";

    // Overpush
    cout << "Try to push more element than maximum(5) [1,2,3,4,5,6]\n";
    for (int i = 1; i <= MAX + 1; i++) s2.push(i);
    cout << "Get last element: " << s2.read() << "\n";

    cout << "End\n";
    return 0;
}
