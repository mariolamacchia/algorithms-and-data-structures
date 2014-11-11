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
}

template <class T>
void _printPreOrder(BinaryTree<T>* t, Node<T>* n)
{
}

template <class T>
void _printInOrder(BinaryTree<T>* t, Node<T>* n)
{
}

#endif
