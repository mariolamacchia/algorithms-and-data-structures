#ifndef _TREE_H
#define _TREE_H

#include "node.h"

template <class T>
class Tree
{
    public:
        Tree();
        Tree(const Tree &);
        ~Tree();

        bool empty();
        bool isLastChild();
        bool isLead();

        Node<T>* getRoot();
        Node<T>* getParent(Node<T>*);
        Node<T>* getSibling(Node<T>*);
        Node<T>* getChild(Node<T>*);

        void insert(Node<T>*, Node<T>*, Tree<T>*);
        void remove(Node<T>*);
        void setRoot(T);
        

    private:
        void create();
};

template <class T>
Tree<T>::Tree()
{
}

template <class T>
Tree<T>::Tree(const Tree &)
{
}

template <class T>
Tree<T>::~Tree()
{
}

template <class T>
bool Tree<T>::empty()
{
}

template <class T>
bool Tree<T>::isLastChild()
{
}

template <class T>
bool Tree<T>::isLead()
{
}

template <class T>
Node<T>* Tree<T>::getRoot()
{
}

template <class T>
Node<T>* Tree<T>::getParent(Node<T>*)
{
}

template <class T>
Node<T>* Tree<T>::getSibling(Node<T>*)
{
}

template <class T>
Node<T>* Tree<T>::getChild(Node<T>*)
{
}

template <class T>
void Tree<T>::insert(Node<T>*, Node<T>*, Tree<T>*)
{
}

template <class T>
void Tree<T>::remove(Node<T>*)
{
}

template <class T>
void Tree<T>::setRoot(T)
{
}

template <class T>
void Tree<T>::create()
{
}

#endif
