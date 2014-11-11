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
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
}

template <class T>
Node<T>* Node<T>::getLeftChild() const
{
    return leftChild;
}

template <class T>
Node<T>* Node<T>::getRightChild() const
{
    return rightChild;
}

template <class T>
Node<T>* Node<T>::getParent() const
{
    return parent;
}

template <class T>
T Node<T>::getValue() const
{
    return value;
}

template <class T>
void Node<T>::setLeftChild(Node<T>* n)
{
    leftChild = n;
}

template <class T>
void Node<T>::setRightChild(Node<T>* n)
{
    rightChild = n;
}

template <class T>
void Node<T>::setParent(Node<T>* n)
{
    parent = n;
}

template <class T>
void Node<T>::setValue(T v)
{
    value = v;
}

#endif
