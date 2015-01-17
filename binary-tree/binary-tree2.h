#ifndef _BINTREE_H
#define _BINTREE_H

#include <climits>
#include "node.h"

template <class T>
class BinaryTree
{
    public:
        typedef int node;
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

        T read(int) const;
        void write(int, T);

    private:
        void copySubtree(BinaryTree<T>* source, int sourceNode, int destNode);
        int* values;
        static const int maxLength = 100;
        static const int empty = INT_MAX - 1;
        static const int undefined = INT_MAX;
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    values = new int[maxLength];
    for (int i = 0; i < maxLength; i++) values[i] = undefined;
}

template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>* left, BinaryTree<T>* right)
{
    values = new int[maxLength];
    for (int i = 1; i < maxLength; i++) values[i] = undefined;
    setRoot(empty);
    copySubtree(left, left->getRoot(), getLeftChild(getRoot()));
    copySubtree(right, right->getRoot(), getRightChild(getRoot()));
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    delete values;
}

template <class T>
void BinaryTree<T>::copySubtree(BinaryTree<T>* source, int sourceNode, int destNode)
{
    write(destNode, source->read(sourceNode));
    if (source->hasLeftChild(sourceNode))
    {
        copySubtree(source, source->getLeftChild(sourceNode),
                    getLeftChild(destNode));
    }
    if (source->hasRightChild(sourceNode))
    {
        copySubtree(source, source->getRightChild(sourceNode),
                    getRightChild(destNode));
    }
}

template <class T>
int BinaryTree<T>::getRoot() const
{
    return 0;
}

template <class T>
int BinaryTree<T>::getLeftChild(int n) const
{
    return 2 * n + 1;
}

template <class T>
int BinaryTree<T>::getRightChild(int n) const
{
    return 2 * n + 2;
}

template <class T>
bool BinaryTree<T>::isEmpty() const
{
    return read(getRoot()) == undefined;
}

template <class T>
bool BinaryTree<T>::hasLeftChild(int n) const
{
    return values[getLeftChild(n)] != undefined;
}

template <class T>
bool BinaryTree<T>::hasRightChild(int n) const
{
    return values[getRightChild(n)] != undefined;
}

template <class T>
bool BinaryTree<T>::isLeaf(int n) const
{
    return (!(hasLeftChild(n) || hasRightChild(n)));
}

template <class T>
void BinaryTree<T>::insertLeft(int n, BinaryTree<T>* t)
{
    copySubTree(t, t->getRoot(), getLeftChild(n));
}

template <class T>
void BinaryTree<T>::insertRight(int n, BinaryTree<T>* t)
{
    copySubTree(t, t->getRoot(), getRightChild(n));
}

template <class T>
void BinaryTree<T>::setRoot(T v)
{
    values[0] = v;
}

template <class T>
void BinaryTree<T>::removeLeftChild(int n)
{
    values[getLeftChild(n)] = undefined;
}

template <class T>
void BinaryTree<T>::removeRightChild(int n)
{
    values[getRightChild(n)] = undefined;
}

template <class T>
T BinaryTree<T>::read(int i) const
{
    return values[i];
}

template <class T>
void BinaryTree<T>::write(int i, T value)
{
    values[i] = value;
}

#endif
