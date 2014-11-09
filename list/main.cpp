#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    Cell<int>* c;

    // Test constructor
    cout << "Create empty list\n";
    List<int> l1;

    // Test isEmpty
    cout << "Is empty? " << l1.isEmpty() << "\n";

    // Test insert
    cout << "Fill with [1, 2, 3, 4, 5]\n";

    c = l1.getFirst();
    for (int i = 0; i < 5; i++) l1.insert(c, i+1);

    // Test getNext and read
    cout << "Get second element: ";

    c = l1.getNext(l1.getFirst());

    cout << l1.read(c) << "\n";

    // Test getPrevious and write
    cout << "Get first element and replace with 10: ";

    c = l1.getPrevious(c);
    cout << l1.read(c) << "  > ";
    l1.write(c, 10);
    cout << l1.read(l1.getFirst()) << "\n";
    
    // Test copy constructor and eol
    cout << "Create copy of list\n";
    List<int> l2(l1);
    c = l2.getFirst();
    cout << "[";
    while (!l2.eol(c))
    {
        cout << l2.read(c) << ", ";
        c = l2.getNext(c);
    }
    cout << "]\n";

    // Test remove
    cout << "Empty first list\n";
    while (!l1.isEmpty())
    {
        l1.remove(l1.getFirst());
    }

    cout << "Is copied list empty? " << l2.isEmpty() << "\n";

    cout << "End";
    return 0;
}
