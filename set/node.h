#ifndef _NODE_H
#define _NODE_H

template <class T>
class Node
{
    public:
        void setNext(Node<T>*);
        Node<T>* getNext();
        void setValue(T);
        T getValue();

    private:
        Node<T>* next = NULL;
        T value;
};

template <class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template <class T>
void Node<T>::setNext(Node<T>* n)
{
    next = n;
}

template <class T>
void Node<T>::setValue(T v)
{
    value = v;
}

template <class T>
T Node<T>::getValue()
{
    return value;
}


#endif
