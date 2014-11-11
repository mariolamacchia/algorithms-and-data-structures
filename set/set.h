#ifndef _SET_H
#define _SET_H

#include "node.h"

template <class T>
class Set
{
    public:
        Set();
        ~Set();

        bool isEmpty() const;
        bool isEndOfSet(Node<T>*) const;
        bool has(T) const;

        Node<T>* getFirst() const;
        Node<T>* getNext(Node<T>*) const;

        void insert(T);
        void remove(T);

        T read(Node<T>*);
};

template <class T>
Set<T>::Set()
{
}

template <class T>
Set<T>::~Set()
{
}

template <class T>
bool Set<T>::isEmpty() const
{
    return true;
}

template <class T>
bool Set<T>::isEndOfSet(Node<T>* n) const
{
    return true;
}

template <class T>
bool Set<T>::has(T) const
{
    return true;
}

template <class T>
Node<T>* Set<T>::getFirst() const
{
    return NULL;
}

template <class T>
Node<T>* Set<T>::getNext(Node<T>*) const
{
    return NULL;
}

template <class T>
void Set<T>::insert(T)
{
}

template <class T>
void Set<T>::remove(T)
{
}

template <class T>
T Set<T>::read(Node<T> * n)
{
    return 0;
}

#endif
