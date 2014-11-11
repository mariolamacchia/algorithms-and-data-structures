#include <iostream>
#include "set.h"
#include "operations.h"

using namespace std;

void print(Set<int>* s)
{
    Node<int>* n = s->getFirst();
    while (!s->isEndOfSet(n))
    {
        cout << s->read(n) << ", ";
        n = s->getNext(n);
    }
}

int main()
{
    cout << "Create empty set: ";
    Set<int>* s1 = new Set<int>;
    cout << s1->isEmpty() <<"\n";

    cout << "Insert 1,2,3,4\n";
    for (int i = 1; i <= 4; i++)
    {
        s1->insert(i);
    }

    cout << "Insert dublicate 4\n";
    s1->insert(4);

    cout << "Insert 0\n";

    s1->insert(0);

    cout << "Print set: ";
    print(s1);
    cout << "\n";
    
    cout << "Create sets [3,4,5,6], [11, 12,13]\n";
    Set<int> * s2 = new Set<int>,
             * s3 = new Set<int>;
    for (int i = 3; i <= 6; i++) s2->insert(i);
    for (int i = 11; i <= 13; i++) s3->insert(i);

    cout << "Remove 1 from first set\n";
    s1->remove(1);

    cout << "Remove 10 from first set\n";
    s1->remove(10);

    cout << "Is 1 in first set? " << s1->has(1) << "\n";
    cout << "Is 0 in first set? " << s1->has(0) << "\n";

    cout << "Union s1, s3: ";
    print(sum(s1, s3));
    cout << "\n";

    cout << "Intersection s1, s2: ";
    print(intersection(s1, s2));
    cout << "\n";

    cout << "Intersection s1, s3: ";
    print(intersection(s1, s3));
    cout << "\n";

    cout << "s1 - s2: ";
    print(difference(s1, s2));
    cout << "\n";

    cout << "End\n";
}
