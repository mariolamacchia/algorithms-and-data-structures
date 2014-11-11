#ifndef _TREE_H
#define _TREE_H

#include "node.h"

template <class T>
class Tree
{
    public:
        Tree();
        ~Tree();

        bool isEmpty() const;
        bool isLastChild(Node<T>*) const;
        bool isLeaf(Node<T>*) const;

        Node<T>* getRoot() const;
        Node<T>* getParent(Node<T>*) const;
        Node<T>* getSibling(Node<T>*) const;
        Node<T>* getChild(Node<T>*) const;

        void insert(Node<T>*, Node<T>*, Tree<T>*);
        void remove(Node<T>*);
        void setRoot(T);
        

    private:
        void create();
        Node<T>* root;
};

template <class T>
Tree<T>::Tree()
{
    create();
}

template <class T>
Tree<T>::~Tree()
{
    delete root;
}

template <class T>
bool Tree<T>::isEmpty() const
{
    return root == NULL;
}

template <class T>
bool Tree<T>::isLastChild(Node<T> * n) const
{
    return n->getSibling() == NULL;
}

template <class T>
bool Tree<T>::isLeaf(Node<T> * n) const
{
    return n->getChild() == NULL;
}

template <class T>
Node<T>* Tree<T>::getRoot() const
{
    return root;
}

template <class T>
Node<T>* Tree<T>::getParent(Node<T>* n) const
{
    return n->getParent();
}

template <class T>
Node<T>* Tree<T>::getSibling(Node<T>* n) const
{
    return n->getSibling();
}

template <class T>
Node<T>* Tree<T>::getChild(Node<T>* n) const
{
    return n->getChild();
}

template <class T>
void Tree<T>::insert(Node<T>* np, Node<T>* ns, Tree<T>* t)
{
    t->getRoot()->setParent(np);
    if (np == ns)
    {
        // t's root becomes np's first child
        t->getRoot()->setSibling(np->getChild());
        np->setChild(t->getRoot());
    }
    else
    {
        // t's root becomes ns's sibling
        t->getRoot()->setSibling(ns->getSibling());
        ns->setSibling(t->getRoot());
    }
}

template <class T>
void Tree<T>::remove(Node<T>* n)
{
    // if n is root
    if (n == getRoot())
    {
        delete n;
        root = NULL;
    }
    // if n is first child
    else if (n->getParent()->getChild() == n)
    {
        n->getParent()->setChild(n->getSibling());
        delete n;
    }
    else
    {
        Node<T> * nb = n->getParent()->getChild();
        while (nb->getSibling() != n) nb = nb->getSibling();
        nb->setSibling(n->getSibling());
        delete n;
    }
}

template <class T>
void Tree<T>::setRoot(T v)
{
    root = new Node<T>;
    root->setValue(v);
}

template <class T>
void Tree<T>::create()
{
    root = NULL;
}

#endif
