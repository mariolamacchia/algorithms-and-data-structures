#ifndef _LIST_H
#define _LIST_H

#include "cell.h"

template <class T>
class List
{
    public:
        List();
        List(const List&);
        ~List();

        void createList();

        bool eol(Cell<T>*) const;
        bool isEmpty() const;

        Cell<T>* getFirst() const;
        Cell<T>* getNext(Cell<T>*) const;
        Cell<T>* getPrevious(Cell<T>*) const;

        T read(Cell<T>*) const;
        void write(Cell<T>*, T);

        void insert(Cell<T>*, T);
        void remove(Cell<T>*);
    private:
        Cell<T>* pivot;
};

template <class T>
List<T>::List()
{
    createList();
}

template <class T>
List<T>::List(const List & l)
{
    Cell<T>* c1, *c2;
    createList();
    c1 = l.getFirst();
    c2 = getFirst();
    while (!l.eol(c1))
    {
        insert(c2, l.read(c1));
        c1 = l.getNext(c1);
    }
}

template <class T>
List<T>::~List()
{
    Cell<T>* c;
    while (!isEmpty())
    {
        remove(getFirst());
    }
    delete pivot;
}


template <class T>
void List<T>::createList()
{
    pivot = new Cell<T>;
    pivot->setNext(pivot);
    pivot->setPrevious(pivot);
}


template <class T>
bool List<T>::eol(Cell<T>* c) const
{
    return c->getValue() == pivot->getValue();
}


template <class T>
bool List<T>::isEmpty() const
{
    return eol(getFirst());
}


template <class T>
Cell<T>* List<T>::getFirst() const
{
    return pivot->getNext();
}


template <class T>
Cell<T>* List<T>::getNext(Cell<T>* c) const
{
    return c->getNext();
}


template <class T>
Cell<T>* List<T>::getPrevious(Cell<T>* c) const
{
    return c->getPrevious();
}


template <class T>
T List<T>::read(Cell<T>* c) const
{
    return c->getValue();
}


template <class T>
void List<T>::write(Cell<T>* c, T v)
{
    c->setValue(v);
}


template <class T>
void List<T>::insert(Cell<T>* c, T v)
{
    Cell<T> *n = new Cell<T>;
    n->setValue(v);
    n->setNext(c);
    n->setPrevious(c->getPrevious());
    c->getPrevious()->setNext(n);
    c->setPrevious(n);
}


template <class T>
void List<T>::remove(Cell<T>* c)
{
    c->getPrevious()->setNext(c->getNext());
    c->getNext()->setPrevious(c->getPrevious());
    delete c;
}


#endif
