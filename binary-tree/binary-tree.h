#ifndef _BINTREE_H
#define _BINTREE_H

#include "node.h"

template <class T>
class BinaryTree
{
    public:
        BinaryTree();
        BinaryTree(BinaryTree<T>* left, BinaryTree<T>* right);
        ~BinaryTree();

        Node<T>* getRoot() const;
        Node<T>* getLeftChild() const;
        Node<T>* getRightChild() const;

        bool isEmpty() const;
        bool hasLeftChild(Node<T>*) const;
        bool hasRightChild(Node<T>*) const;
        bool isLeaf(Node<T>*) const;

        void insertLeft(BinaryTree<T>*);
        void insertRight(BinaryTree<T>*);
        void setRoot(T);

        void removeRightChild();
        void removeLeftChild();
    private:
        void create();
        Node<T>* root;
};

template <class T>
BinaryTree<T>::BinaryTree()
{
}

template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>* left, BinaryTree<T>* right)
{
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
}

template <class T>
Node<T>* BinaryTree<T>::getRoot() const
{
    return NULL;
}

template <class T>
Node<T>* BinaryTree<T>::getLeftChild() const
{
    return NULL;
}

template <class T>
Node<T>* BinaryTree<T>::getRightChild() const
{
    return NULL;
}

template <class T>
bool BinaryTree<T>::isEmpty() const
{
    return true;
}

template <class T>
bool BinaryTree<T>::hasLeftChild(Node<T>* n) const
{
    return true;
}

template <class T>
bool BinaryTree<T>::hasRightChild(Node<T>* n) const
{
    return true;
}

template <class T>
bool BinaryTree<T>::isLeaf(Node<T>* n) const
{
    return true;
}

template <class T>
void BinaryTree<T>::insertLeft(BinaryTree<T>* t)
{
}

template <class T>
void BinaryTree<T>::insertRight(BinaryTree<T>* t)
{
}

template <class T>
void BinaryTree<T>::setRoot(T)
{
}

template <class T>
void BinaryTree<T>::create()
{
}

template <class T>
void BinaryTree<T>::removeRightChild()
{
}

template <class T>
void BinaryTree<T>::removeLeftChild()
{
}


#endif
