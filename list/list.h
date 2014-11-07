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
};

template <class T>
List<T>::List()
{
}

template <class T>
List<T>::List(const List&)
{
}

template <class T>
List<T>::~List()
{
}


template <class T>
void List<T>::createList()
{
}


template <class T>
bool List<T>::eol(Cell<T>*) const
{
    return false;
}


template <class T>
bool List<T>::isEmpty() const
{
    return false;
}


template <class T>
Cell<T>* List<T>::getFirst() const
{
    return NULL;
}


template <class T>
Cell<T>* List<T>::getNext(Cell<T>*) const
{
    return NULL;
}


template <class T>
Cell<T>* List<T>::getPrevious(Cell<T>*) const
{
    return NULL;
}


template <class T>
T List<T>::read(Cell<T>*) const
{
    return 0;
}


template <class T>
void List<T>::write(Cell<T>*, T)
{
}


template <class T>
void List<T>::insert(Cell<T>*, T)
{
}


template <class T>
void List<T>::remove(Cell<T>*)
{
}


#endif
