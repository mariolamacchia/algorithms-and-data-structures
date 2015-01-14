#ifndef _BINTREE_H
#define _BINTREE_H

#define MAX_LENGTH 100

#include "node.h"

template <class T>
class BinaryTree
{
    public:
        BinaryTree();
        BinaryTree(BinaryTree<T>* left, BinaryTree<T>* right);
        ~BinaryTree();

        int getRoot() const;
        int getLeftChild(int) const;
        int getRightChild(int) const;
 
        bool isEmpty() const;
        bool hasLeftChild(int) const;
        bool hasRightChild(int) const;
        bool isLeaf(int) const;

        void insertLeft(int ,BinaryTree<T>*);
        void insertRight(int, BinaryTree<T>*);
        void setRoot(T);

        void removeRightChild(int);
        void removeLeftChild(int);

    private:
        int* values;
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    values = new int[MAX_LENGTH];
}

template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>* left, BinaryTree<T>* right)
{
    values = new int[MAX_LENGTH];
    root = new Node<T>;
    root->setLeftChild(left->getRoot());
    root->setRightChild(right->getRoot());
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    delete values;
}

template <class T>
int BinaryTree<T>::getRoot() const
{
    return 0;
}

template <class T>
int BinaryTree<T>::getLeftChild(intn) const
{
    return n->getLeftChild();
}

template <class T>
int BinaryTree<T>::getRightChild(intn) const
{
    return n->getRightChild();
}

template <class T>
bool BinaryTree<T>::isEmpty() const
{
    return root == NULL;
}

template <class T>
bool BinaryTree<T>::hasLeftChild(int n) const
{
    return n->getLeftChild() != NULL;
}

template <class T>
bool BinaryTree<T>::hasRightChild(int n) const
{
    return n->getRightChild() != NULL;
}

template <class T>
bool BinaryTree<T>::isLeaf(int n) const
{
    return (!(hasLeftChild(n) || hasRightChild(n)));
}

template <class T>
void BinaryTree<T>::insertLeft(int n, BinaryTree<T>* t)
{
    n->setLeftChild(t->getRoot());
    t->getRoot()->setParent(n);
}

template <class T>
void BinaryTree<T>::insertRight(int n, BinaryTree<T>* t)
{
    n->setRightChild(t->getRoot());
    t->getRoot()->setParent(n);
}

template <class T>
void BinaryTree<T>::setRoot(T v)
{
    if (root == NULL) root = new Node<T>;
    root->setValue(v);
}

template <class T>
void BinaryTree<T>::removeLeftChild(int n)
{
    if (hasLeftChild(n))
    {
        delete getLeftChild(n);
        n->setLeftChild(NULL);
    }
}

template <class T>
void BinaryTree<T>::removeRightChild(int n)
{
    if (hasRightChild(n))
    {
        delete getRightChild(n);
        n->setRightChild(NULL);
    }
}

#endif
