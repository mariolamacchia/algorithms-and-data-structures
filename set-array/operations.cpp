#include "operations.h"

Set* sum(Set* s1, Set* s2)
{
    Set* s = new Set;
    typename Set::cell n = s1->getFirst();
    while (!s1->isEndOfSet(n))
    {
        s->insert(s1->read(n));
        n = s1->getNext(n);
    }
    n = s2->getFirst();
    while (!s2->isEndOfSet(n))
    {
        s->insert(s2->read(n));
        n = s2->getNext(n);
    }
    return s;
}

Set* intersection(Set* s1, Set* s2)
{
    Set* s = new Set;
    typename Set::cell n = s1->getFirst();
    while (!s1->isEndOfSet(n))
    {
        if (s2->has(s1->read(n))) s->insert(s1->read(n));
        n = s1->getNext(n);
    }
    return s;
}

Set* difference(Set* s1, Set* s2)
{
    Set* s = new Set;
    typename Set::cell n = s1->getFirst();
    while (!s1->isEndOfSet(n))
    {
        if (!s2->has(s1->read(n))) s->insert(s1->read(n));
        n = s1->getNext(n);
    }
    return s;
}
