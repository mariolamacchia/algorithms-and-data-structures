#ifndef _SET_OPERATIONS_H
#define _SET_OPERATIONS_H

#include "set.h"

template <class T>
Set<T>* sum(Set<T>* s1, Set<T>* s2)
{
    Set<T>* s = new Set<T>;
    typename Set<T>::cell n = s1->getFirst();
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

template <class T>
Set<T>* intersection(Set<T>* s1, Set<T>* s2)
{
    Set<T>* s = new Set<T>;
    typename Set<T>::cell n = s1->getFirst();
    while (!s1->isEndOfSet(n))
    {
        if (s2->has(s1->read(n))) s->insert(s1->read(n));
        n = s1->getNext(n);
    }
    return s;
}

template <class T>
Set<T>* difference(Set<T>* s1, Set<T>* s2)
{
    Set<T>* s = new Set<T>;
    typename Set<T>::cell n = s1->getFirst();
    while (!s1->isEndOfSet(n))
    {
        if (!s2->has(s1->read(n))) s->insert(s1->read(n));
        n = s1->getNext(n);
    }
    return s;
}

#endif
