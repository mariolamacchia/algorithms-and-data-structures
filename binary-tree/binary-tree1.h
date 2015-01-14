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
        Node<T>* getLeftChild(Node<T>*) const;
        Node<T>* getRightChild(Node<T>*) const;

        bool isEmpty() const;
        bool hasLeftChild(Node<T>*) const;
        bool hasRightChild(Node<T>*) const;
        bool isLeaf(Node<T>*) const;

        void insertLeft(Node<T>* ,BinaryTree<T>*);
        void insertRight(Node<T>*, BinaryTree<T>*);
        void setRoot(T);

        void removeRightChild(Node<T>*);
        void removeLeftChild(Node<T>*);

    private:
        Node<T>* root;
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>* left, BinaryTree<T>* right)
{
    root = new Node<T>;
    root->setLeftChild(left->getRoot());
    root->setRightChild(right->getRoot());
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    delete root;
}

template <class T>
Node<T>* BinaryTree<T>::getRoot() const
{
    return root;
}

template <class T>
Node<T>* BinaryTree<T>::getLeftChild(Node<T>*n) const
{
    return n->getLeftChild();
}

template <class T>
Node<T>* BinaryTree<T>::getRightChild(Node<T>*n) const
{
    return n->getRightChild();
}

template <class T>
bool BinaryTree<T>::isEmpty() const
{
    return root == NULL;
}

template <class T>
bool BinaryTree<T>::hasLeftChild(Node<T>* n) const
{
    return n->getLeftChild() != NULL;
}

template <class T>
bool BinaryTree<T>::hasRightChild(Node<T>* n) const
{
    return n->getRightChild() != NULL;
}

template <class T>
bool BinaryTree<T>::isLeaf(Node<T>* n) const
{
    return (!(hasLeftChild(n) || hasRightChild(n)));
}

template <class T>
void BinaryTree<T>::insertLeft(Node<T>* n, BinaryTree<T>* t)
{
    n->setLeftChild(t->getRoot());
    t->getRoot()->setParent(n);
}

template <class T>
void BinaryTree<T>::insertRight(Node<T>* n, BinaryTree<T>* t)
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
void BinaryTree<T>::removeLeftChild(Node<T>* n)
{
    if (hasLeftChild(n))
    {
        delete getLeftChild(n);
        n->setLeftChild(NULL);
    }
}

template <class T>
void BinaryTree<T>::removeRightChild(Node<T>* n)
{
    if (hasRightChild(n))
    {
        delete getRightChild(n);
        n->setRightChild(NULL);
    }
}

#endif
