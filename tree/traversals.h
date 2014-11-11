#ifndef _TRAVERSALS_H
#define _TRAVERSALS_H

#include "tree.h"
#include <iostream>

using namespace std;

template <class T>
void printInOrder(Tree<T>* t, int in)
{
    cout << "[";
    _printInOrder(t, t->getRoot(), in);
    cout << "]\n";
}

template <class T>
void printPreOrder(Tree<T>* t)
{
    cout << "[";
    _printPreOrder(t, t->getRoot());
    cout << "]\n";
}

template <class T>
void printPostOrder(Tree<T>* t)
{
    cout << "[";
    _printPostOrder(t, t->getRoot());
    cout << "]\n";
}

template <class T>
void _printInOrder(Tree<T>* t, Node<T>* n, int in)
{
    if (t->isLeaf(n)) cout << n->getValue() << ", ";
    else
    {
        int i = 0;
        Node<T>* c = t->getChild(n);
        while (!t->isLastChild(c) && i != in)
        {
            _printInOrder(t, c, in);
            c = t->getSibling(c);
            i++;
        }
        // if i < in c is last child and it must be printed
        if (i < in) _printInOrder(t, c, in);
        cout << n->getValue() << ", ";
        // if i < in means that children are finished
        if (i == in)
        {
            while (!t->isLastChild(c))
            {
                _printInOrder(t, c, in);
                c = t->getSibling(c);
            }
            _printInOrder(t, c, in);
        }
    }
}

template <class T>
void _printPreOrder(Tree<T>* t, Node<T>* n)
{
    if (t->isLeaf(n)) cout << n->getValue() << ", ";
    else
    {
        Node<T>* c = t->getChild(n);
        while (!t->isLastChild(c))
        {
            _printPreOrder(t, c);
            c = t->getSibling(c);
        }
        _printPreOrder(t, c);
        cout << n->getValue() << ", ";
    }
}

template <class T>
void _printPostOrder(Tree<T>* t, Node<T>* n)
{
    cout << n->getValue() << ", ";
    if (!t->isLeaf(n))
    {
        Node<T>* c = t->getChild(n);
        while (!t->isLastChild(c))
        {
            _printPostOrder(t, c);
            c = t->getSibling(c);
        }
        _printPostOrder(t, c);
    }
}

#endif
