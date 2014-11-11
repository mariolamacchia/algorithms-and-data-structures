#ifndef _TRASVERSALS_H
#define _TRASVERSALS_H

#include <iostream>
#include "binary-tree.h"

using namespace std;

template <class T>
void printPostOrder(BinaryTree<T>* t)
{
    cout << "[";
    _printPostOrder(t, t->getRoot());
    cout << "]\n";
}

template <class T>
void printPreOrder(BinaryTree<T>* t)
{
    cout << "[";
    _printPreOrder(t, t->getRoot());
    cout << "]\n";
}

template <class T>
void printInOrder(BinaryTree<T>* t)
{
    cout << "[";
    _printInOrder(t, t->getRoot());
    cout << "]\n";
}

template <class T>
void _printPostOrder(BinaryTree<T>* t, Node<T>* n)
{
    cout << n->getValue() << ", ";    
    if (t->hasLeftChild(n)) _printPostOrder(t, t->getLeftChild(n));
    if (t->hasRightChild(n)) _printPostOrder(t, t->getRightChild(n));
}

template <class T>
void _printPreOrder(BinaryTree<T>* t, Node<T>* n)
{
    if (t->hasLeftChild(n)) _printPreOrder(t, t->getLeftChild(n));
    if (t->hasRightChild(n)) _printPreOrder(t, t->getRightChild(n));
    cout << n->getValue() << ", ";    
}

template <class T>
void _printInOrder(BinaryTree<T>* t, Node<T>* n)
{
    if (t->hasLeftChild(n)) _printInOrder(t, t->getLeftChild(n));
    cout << n->getValue() << ", ";    
    if (t->hasRightChild(n)) _printInOrder(t, t->getRightChild(n));
}

#endif
