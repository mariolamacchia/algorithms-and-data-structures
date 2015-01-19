#include <iostream>
#include "priority-queue.h"
#include "algorithms.h"
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

    cout << "Heap sort of [1, 3, 2, 9, 8]";
    startTest("[1, 2, 3, 8, 9, ]");
    int a[] = {1, 3, 2, 9, 8};
    heapSort(a, 5);
    cout << "[";
    for (int i = 0; i < 5; i++) cout << a[i] << ", ";
    cout << "]";
    endTest();
    
    cout << "End";
}
