#include <iostream>
#include <cstdlib>
#include <ctime>
#include "list.h"
#include "sorting.h"

using namespace std;

void printIntList(List<int> *l)
{
    typename List<int>::cell c = l->getFirst();
    cout << "\033[1;31m[";
    while (!l->eol(c))
    {
        cout << l->read(c) << ", ";
        c = l->getNext(c);
    }
    cout << "]\033[0m";
}

void startTest(string it)
{
    cout << "\n(it should be \"" << it << "\"): \033[1;31m";
}

void endTest()
{
    cout << "\033[0m\n\n";
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
    cout << "\nFill with [1, 2, 3, 4, 5]";
    startTest("[1, 2, 3, 4, 5,]");
    c = l1.getFirst();
    for (int i = 0; i < 5; i++) l1.insert(c, i+1);
    printIntList(&l1);
    endTest();

    // Test getNext and read
    cout << "\nGet second element:";
    startTest("2");
    c = l1.getNext(l1.getFirst());
    cout << l1.read(c);
    endTest();

    // Test getPrevious and write
    cout << "\nGet first element and replace with 10:";
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
    startTest("1");
    cout << l2.isEmpty();
    endTest();

    // Merge sort
    List<int>* l;
    l = new List<int>;
    c = l->getFirst();
    for (int i = 0; i < 10; i++) l->insert(c, i);
    cout << "Merge ordered list [1..10]:";
    startTest("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10,]");
    l = mergeSort(l);
    printIntList(l);
    endTest();

    cout << "Merge random list ";
    l = new List<int>;
    c = l->getFirst();
    for (int i = 10; i > 0; i--) l->insert(c, rand() % 10);
    printIntList(l);
    startTest("ordered");
    l = mergeSort(l);
    printIntList(l);
    endTest();

    cout << "End";
    return 0;
}
