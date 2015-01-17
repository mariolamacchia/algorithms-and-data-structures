#include <iostream>
#include "set.h"
#include "operations.h"
#include "../tests.h"

using namespace std;

void print(Set* s)
{
    typename Set::cell n = s->getFirst();
    cout << "[";
    while (!s->isEndOfSet(n))
    {
        cout << s->read(n) << ", ";
        n = s->getNext(n);
    }
    cout << "]";
}

int main()
{
    cout << "Create empty set: ";
    Set* s1 = new Set;
    cout << "\nIs set empty?";
    startTest("1");
    cout << s1->isEmpty();
    endTest();

    cout << "Insert 1,2,3,4\n";
    for (int i = 1; i <= 4; i++)
    {
        s1->insert(i);
    }
    startTest("[1, 2, 3, 4, ]");
    print(s1);
    endTest();

    cout << "Insert dublicate 4\n";
    s1->insert(4);
    startTest("[1, 2, 3, 4, ]");
    print(s1);
    endTest();

    cout << "Insert 0\n";

    s1->insert(0);

    startTest("[0, 1, 2, 3, 4, ]");
    print(s1);
    endTest();
    
    cout << "Create sets [3,4,5,6], [11, 12,13]\n";
    Set * s2 = new Set,
        * s3 = new Set;
    for (int i = 3; i <= 6; i++) s2->insert(i);
    for (int i = 11; i <= 13; i++) s3->insert(i);
    startTest("[3, 4, 5, 6, ][11, 12, 13, ]");
    print(s2);
    print(s3);
    endTest();

    cout << "Remove 1 from first set\n";
    s1->remove(1);

    cout << "Remove 10 from first set\n";
    s1->remove(10);

    cout << "Is 1 in first set? ";
    startTest("0");
    cout << s1->has(1);
    endTest();

    cout << "Is 0 in first set? ";
    startTest("1");
    cout << s1->has(0);
    endTest();

    cout << "Union s1, s3: ";
    startTest("[0, 2, 3, 4, 11, 12, 13, ]");
    print(sum(s1, s3));
    endTest();

    cout << "Intersection s1, s2: ";
    startTest("[3, 4, ]");
    print(intersection(s1, s2));
    endTest();

    cout << "Intersection s1, s3: ";
    startTest("[]");
    print(intersection(s1, s3));
    endTest();

    cout << "s1 - s2: ";
    startTest("[0, 2, ]");
    print(difference(s1, s2));
    endTest();

    cout << "End\n";
}
