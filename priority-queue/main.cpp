#include <iostream>
#include "priority-queue.h"
#include "../tests.h"

using namespace std;

int main()
{
    PriorityQueue<int> * p = new PriorityQueue<int>();
    
    cout << "Is p empty?";
    startTest("1");
    cout << p->isEmpty();
    endTest();

    cout << "Insert into p: [5, 3, 9, 2, 10]\n";
    p->insert(5);
    p->insert(3);
    p->insert(9);
    p->insert(2);
    p->insert(10);
    cout << "Is empty?";
    startTest("0");
    cout << p->isEmpty();
    endTest();

    cout << "Minimum is:";
    startTest("2");
    cout << p->read();
    endTest();

    cout << "Extract all";
    startTest("[2, 3, 5, 9, 10, ]");
    cout << "[";
    while (!p->isEmpty()) cout << p->pull() << ", ";
    cout << "]";
    endTest();
    
    cout << "End";
}
