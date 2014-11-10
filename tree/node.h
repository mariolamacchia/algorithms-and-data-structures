#ifndef _NODE_H
#define _NODE_H

template <class T>
class Node
{
    public:
        Node();
        
        Node* getParent();
        Node* getSibling();
        Node* getChild();
        T getValue();
        void setParent(Node<T>*);
        void setSibling(Node<T>*);
        void setChild(Node<T>*);
        void setValue(T);
    private:
        Node* parent;
        Node* sibling;
        Node* child;
        T value;
};

template <class T>
Node<T>::Node()
{
    parent = NULL;
    sibling = NULL;
    child = NULL;
}

template <class T>
Node<T>* Node<T>::getParent()
{
    return parent;
}

template <class T>
Node<T>* Node<T>::getSibling()
{
    return sibling;
}

template <class T>
Node<T>* Node<T>::getChild()
{
    return child;
}

template <class T>
T Node<T>::getValue()
{
    return value;
}

template <class T>
void Node<T>::setParent(Node<T>* n)
{
    parent = n;
}

template <class T>
void Node<T>::setSibling(Node<T>* n)
{
    sibling = n;
}

template <class T>
void Node<T>::setChild(Node<T>* n)
{
    child = n;
}

template <class T>
void Node<T>::setValue(T v)
{
    value = v;
}

#endif
