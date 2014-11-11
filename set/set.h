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

        T read(Node<T>*) const;

    private:
        Node<T>* pivot;
};

template <class T>
Set<T>::Set()
{
    pivot = new Node<T>;
    pivot->setNext(pivot);
}

template <class T>
Set<T>::~Set()
{
    while (!isEmpty()) remove(read(getFirst()));
}

template <class T>
bool Set<T>::isEmpty() const
{
    return pivot->getNext() == pivot;
}

template <class T>
bool Set<T>::isEndOfSet(Node<T>* n) const
{
    return n == pivot;
}

template <class T>
bool Set<T>::has(T v) const
{
    Node<T> * n = getFirst();
    while (!isEndOfSet(n))
    {
        if (read(n) == v) return true;
        if (read(n) > v) return false;
        n = getNext(n);
    }
    return false;
}

template <class T>
Node<T>* Set<T>::getFirst() const
{
    return pivot->getNext();
}

template <class T>
Node<T>* Set<T>::getNext(Node<T>* n) const
{
    return n->getNext();
}

template <class T>
void Set<T>::insert(T v)
{
    if (has(v)) return;
    Node<T> * n1 = pivot,
            * n2 = pivot->getNext();
    while (!(isEndOfSet(n2) || read(n2) > v))
    {
        n1 = n2;
        n2 = getNext(n2);
    }
    Node<T> * n = new Node<T>;
    n->setValue(v);
    n->setNext(n2);
    n1->setNext(n);
}

template <class T>
void Set<T>::remove(T v)
{
    if (!has(v)) return;
    Node<T> * n1 = pivot,
            * n2 = pivot->getNext();
    while (read(n2) != v)
    {
        n1 = n2;
        n2 = getNext(n2);
    }
    n1->setNext(n2->getNext());
    delete n2;
}

template <class T>
T Set<T>::read(Node<T> * n) const
{
    return n->getValue();
}

#endif
