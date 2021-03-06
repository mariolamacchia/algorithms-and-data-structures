#ifndef _SET_H
#define _SET_H

#include "../list/list.h"

template <class T>
class Set : protected List<T>
{
    public:
        using typename List<T>::cell;
        using List<T>::isEmpty;
        using List<T>::getFirst;
        using List<T>::getNext;
        using List<T>::read;

        bool isEndOfSet(typename List<T>::cell) const;
        bool has(T) const;

        void insert(T);
        void remove(T);
};

template <class T>
bool Set<T>::isEndOfSet(typename List<T>::cell c) const
{
    return List<T>::eol(c);
}

template <class T>
bool Set<T>::has(T v) const
{
    typename List<T>::cell n = getFirst();
    while (!List<T>::eol(n))
    {
        if (read(n) == v) return true;
        if (read(n) > v) return false;
        n = getNext(n);
    }
    return false;
}

template <class T>
void Set<T>::insert(T v)
{
    if (has(v)) return;
    typename List<T>::cell n = getFirst();
    while (!(List<T>::eol(n) || read(n) > v))
    {
        n = getNext(n);
    }
    List<T>::insert(n, v);
}

template <class T>
void Set<T>::remove(T v)
{
    if (!has(v)) return;
    typename List<T>::cell n = getFirst();
    while (!(List<T>::eol(n) || read(n) >= v))
    {
        n = getNext(n);
    }
    if (read(n) == v) List<T>::remove(n);
}

#endif
