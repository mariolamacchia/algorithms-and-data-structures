#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../tests.h"
#include "list.h"
#include "algorithms.h"

using namespace std;

void printIntList(List<int> *l)
{
    typename List<int>::cell c = l->getFirst();
    cout << "[";
    while (!l->eol(c))
    {
        cout << l->read(c) << ", ";
        c = l->getNext(c);
    }
    cout << "]";
}

int main()
{
    srand(time(0));
    typename List<int>::cell c;

    // Test constructor
    cout << "Create empty list";
    List<int> l1;

    // Test isEmpty
    cout << "\nIs list empty?";
    startTest("1");
    cout << l1.isEmpty();
    endTest();

    // Test insert
    cout << "Fill with [1, 2, 3, 4, 5]";
    startTest("[1, 2, 3, 4, 5,]");
    for (int i = 5; i > 0; i--)
    {
        c = l1.getFirst();
        l1.insert(c, i);
    }
    printIntList(&l1);
    endTest();

    // Test getNext and read
    cout << "Get second element:";
    startTest("2");
    c = l1.getNext(l1.getFirst());
    cout << l1.read(c);
    endTest();

    // Test getPrevious and write
    cout << "Get first element and replace with 10:";
    c = l1.getPrevious(c);
    startTest("1 > 10");
    cout << l1.read(c) << " > ";
    l1.write(c, 10);
    cout << l1.read(l1.getFirst());
    endTest();
    
    // Test copy constructor and eol
    cout << "Create copy of list";
    startTest("[10, 2, 3, 4, 5,]");
    List<int> l2(l1);
    printIntList(&l2);
    endTest();

    // Test remove
    cout << "Empty first list\n";
    while (!l1.isEmpty())
    {
        l1.remove(l1.getFirst());
    }
    cout << "Is copied list empty?";
    startTest("0");
    cout << l2.isEmpty();
    endTest();

    // Merge sort
    List<int>* l;
    l = new List<int>;
    for (int i = 10; i > 0; i--)
    {
        c = l->getFirst();
        l->insert(c, i);
    }
    cout << "Merge sort on ordered list [1..10]:";
    startTest("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10,]");
    l = mergeSort(l);
    printIntList(l);
    endTest();

    cout << "Merge sort on a random list ";
    l = new List<int>;
    for (int i = 10; i > 0; i--)
    {
        c = l->getFirst();
        l->insert(c, rand() % 10);
    }
    printIntList(l);
    startTest("ordered");
    l = mergeSort(l);
    printIntList(l);
    endTest();

    // Search tests
    l = new List<int>;
    for (int i = 9; i > 0; i-=2)
    {
        c = l->getFirst();
        l->insert(c, i);
    }
    cout << "Search 3 and 4 into list [1, 3, 5, 7, 9]:";
    startTest("1, -6");
    cout << search(l, 3) << ", " << search(l, 4);
    endTest();
    cout << "Ordered search 3 and 4 into list [1, 3, 5, 7, 9]:";
    startTest("1, -3");
    cout << searchOrdered(l, 3) << ", " << searchOrdered(l, 4);
    endTest();
    l = new List<int>;
    int value;
    for (int i = 10; i > 0; i--)
    {
        c = l->getFirst();
        int v = rand() % 10;
        if (i == 5) value = v;
        l->insert(c, v);
    }
    cout << "Search " << value << " and -1 into random list ";
    printIntList(l);
    cout << ":";
    startTest("?, -11");
    cout << search(l, value) << ", " << search(l, -1);
    endTest();
    cout << "Ordered search " << value << " and -1 into random list ";
    printIntList(l);
    cout << ":";
    startTest("?, -1");
    cout << searchOrdered(l, value) << ", " << searchOrdered(l, -1);
    endTest();

    cout << "End";
    return 0;
}
