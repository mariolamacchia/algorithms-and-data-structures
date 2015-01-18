#ifndef _BINTREE_H
#define _BINTREE_H

#include "node.h"

template <class T>
class BinaryTree
{
    public:
        typedef Node<T>* node;
        BinaryTree();
        BinaryTree(BinaryTree<T>* left, BinaryTree<T>* right);
        ~BinaryTree();

        Node<T>* getRoot() const;
        Node<T>* getLeftChild(Node<T>*) const;
        Node<T>* getRightChild(Node<T>*) const;
        Node<T>* getParent(Node<T>*) const;

        bool isEmpty() const;
        bool hasLeftChild(Node<T>*) const;
        bool hasRightChild(Node<T>*) const;
        bool isLeaf(Node<T>*) const;

        void insertLeft(Node<T>* ,BinaryTree<T>*);
        void insertRight(Node<T>*, BinaryTree<T>*);
        void setRoot(T);

        void removeRightChild(Node<T>*);
        void removeLeftChild(Node<T>*);
        void remove(Node<T>*);

        T read(Node<T>*) const;
        void write(Node<T>*, T);

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
    if (!left->isEmpty()) insertLeft(root, left);
    if (!right->isEmpty()) insertRight(root, right);
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
Node<T>* BinaryTree<T>::getParent(Node<T>*n) const
{
    return n->getParent();
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
    n->getLeftChild()->setParent(n);
}

template <class T>
void BinaryTree<T>::insertRight(Node<T>* n, BinaryTree<T>* t)
{
    n->setRightChild(t->getRoot());
    n->getRightChild()->setParent(n);
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
        remove(getLeftChild(n));
    }
}

template <class T>
void BinaryTree<T>::removeRightChild(Node<T>* n)
{
    if (hasRightChild(n))
    {
        remove(getRightChild(n));
    }
}

template <class T>
void BinaryTree<T>::remove(Node<T>* n)
{
    if (n != getRoot())
    {
        if (n == getLeftChild(getParent(n)))
        {
            getParent(n)->setLeftChild(NULL);
        }
        else
        {
            getParent(n)->setRightChild(NULL);
        }
    }
    else root = NULL;
    delete n;
    
}

template <class T>
T BinaryTree<T>::read(Node<T>* n) const
{
    return n->getValue();
}

template <class T>
void BinaryTree<T>::write(Node<T>* n, T value)
{
    n->setValue(value);
}

#endif
