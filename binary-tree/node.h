#ifndef _NODE_H
#define _NODE_H

template <class T>
class Node
{
    public:
        Node();

        Node<T>* getLeftChild() const;
        Node<T>* getRightChild() const;
        Node<T>* getParent() const;
        T getValue() const;

        void setLeftChild(Node<T>*);
        void setRightChild(Node<T>*);
        void setParent(Node<T>*);
        void setValue(T);

    private:
        Node<T> * leftChild, * rightChild, * parent;
        T value;
};

template <class T>
Node<T>::Node()
{
}

template <class T>
Node<T>* Node<T>::getLeftChild() const
{
    return NULL;
}

template <class T>
Node<T>* Node<T>::getRightChild() const
{
    return NULL;
}

template <class T>
Node<T>* Node<T>::getParent() const
{
    return NULL;
}

template <class T>
T Node<T>::getValue() const
{
    return 0;
}

template <class T>
void Node<T>::setLeftChild(Node<T>*)
{
}

template <class T>
void Node<T>::setRightChild(Node<T>*)
{
}

template <class T>
void Node<T>::setParent(Node<T>*)
{
}

template <class T>
void Node<T>::setValue(T)
{
}

#endif
