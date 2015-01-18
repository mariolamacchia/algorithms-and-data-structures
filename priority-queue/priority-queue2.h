#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <cmath>
#include "../binary-tree/binary-tree.h"

template <class T>
class PriorityQueue : protected BinaryTree<T>
{
    public:
        PriorityQueue();

        void insert(T);
        T read() const;
        T pull();
        using BinaryTree<T>::isEmpty;
    private:
        int level;
        int lastLevelLeaves;
        typename BinaryTree<T>::node lastLeaf;

        void fixUp(typename BinaryTree<T>::node);
        void fixDown(typename BinaryTree<T>::node);

        void createLastLeaf(typename BinaryTree<T>::node, int, int, T);
        void updateLastLeaf(typename BinaryTree<T>::node, int, int);
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    level = 0;
    lastLevelLeaves = 0;
}

template <class T>
void PriorityQueue<T>::insert(T v)
{
    // Create last leaf on left
    createLastLeaf(BinaryTree<T>::getRoot(), level, lastLevelLeaves, v);

    // Update level and lastLevelLeaves counters
    lastLevelLeaves++;
    if (lastLevelLeaves >= pow(2, level))
    {
        lastLevelLeaves = 0;
        level++;
    }

    // Write leaf
    BinaryTree<T>::write(lastLeaf, v);

    // Fix tree
    fixUp(lastLeaf);
}

template <class T>
T PriorityQueue<T>::read() const
{
    return BinaryTree<T>::read(BinaryTree<T>::getRoot());
}

template <class T>
T PriorityQueue<T>::pull()
{
    // Save root value
    T v = read();

    // If lastLeaf is root, empty tree
    if (lastLeaf == BinaryTree<T>::getRoot())
    {
        BinaryTree<T>::remove(lastLeaf);
        return v;
    }

    // Write lastLeaf value on root
    BinaryTree<T>::write(BinaryTree<T>::getRoot(),
        BinaryTree<T>::read(lastLeaf));

    // Remove lastLeaf
    if (lastLevelLeaves % 2 == 0)
    {
        // lastLeaf is right child
        BinaryTree<T>::removeRightChild(BinaryTree<T>::getParent(lastLeaf));
    }
    else
    {
        // lastLeaf is left child
        BinaryTree<T>::removeLeftChild(BinaryTree<T>::getParent(lastLeaf));
    }

    // Fix tree
    fixDown(BinaryTree<T>::getRoot());

    // Update level and lastLevelLeaves counter
    lastLevelLeaves--;
    if (lastLevelLeaves < 0)
    {
        level--;
        lastLevelLeaves = pow(2, level) - 1;
    }

    // Update lastLeaf pointer
    updateLastLeaf(BinaryTree<T>::getRoot(), level, lastLevelLeaves);

    // return value
    return v;
}

template <class T>
void PriorityQueue<T>::createLastLeaf(
    typename BinaryTree<T>::node root, int level, int lastLevelLeaves, T v)
{
    /* Create a leave on the left of the last level of the tree */

    BinaryTree<T> * t;

    // Create root if empty tree
    if (BinaryTree<T>::isEmpty())
    {
        BinaryTree<T>::setRoot(v);
        lastLeaf = BinaryTree<T>::getRoot();
    }
    // Create child root if doesn't have it
    else if (!BinaryTree<T>::hasLeftChild(root))
    {
        t = new BinaryTree<T>();
        t->setRoot(v);
        BinaryTree<T>::insertLeft(root, t);
        lastLeaf = t->getRoot();
    }
    else if (!BinaryTree<T>::hasRightChild(root))
    {
        t = new BinaryTree<T>();
        t->setRoot(v);
        BinaryTree<T>::insertRight(root, t);
        lastLeaf = t->getRoot();
    }

    // Go to the left child if leaves < (2^level)/2 else go right
    else if (lastLevelLeaves < (int)pow(2, level) / 2)
    {
        createLastLeaf(BinaryTree<T>::getLeftChild(root), level-1,
            lastLevelLeaves, v);
    }
    else
    {
        createLastLeaf(BinaryTree<T>::getRightChild(root), level-1,
            lastLevelLeaves % 2, v);
    }
}

template <class T>
void PriorityQueue<T>::updateLastLeaf(
    typename BinaryTree<T>::node root, int level, int lastLevelLeaves)
{
    /* Get the last leaf on the last level of the tree */

    // return root if root is leaf
    if (BinaryTree<T>::isLeaf(root)) lastLeaf = root;
    else if (lastLevelLeaves <= (int)pow(2,  level) / 2 && lastLevelLeaves > 0)
    {
        updateLastLeaf(BinaryTree<T>::getLeftChild(root), level-1,
            lastLevelLeaves);
    }
    else
    {
        updateLastLeaf(BinaryTree<T>::getRightChild(root), level-1,
            lastLevelLeaves % 2);
    }
}

template <class T>
void PriorityQueue<T>::fixDown(typename BinaryTree<T>::node n)
{
    // Check if node is not leaf
    if (!BinaryTree<T>::isLeaf(n))
    {
        // minNode is left child
        typename BinaryTree<T>::node minNode = BinaryTree<T>::getLeftChild(n);

        // if right child is minor, right child becomes minNode
        if (BinaryTree<T>::hasRightChild(n))
        {
            if (BinaryTree<T>::read(BinaryTree<T>::getLeftChild(n)) >
                BinaryTree<T>::read(BinaryTree<T>::getRightChild(n)))
            {
                minNode = BinaryTree<T>::getRightChild(n);
            }
        }

        // Check node is greater than children
        if (BinaryTree<T>::read(n) > BinaryTree<T>::read(minNode))
        {
            T temp = BinaryTree<T>::read(n);
            BinaryTree<T>::write(n, BinaryTree<T>::read(minNode));
            BinaryTree<T>::write(minNode, temp);
            fixDown(minNode);
        }
    }
}

template <class T>
void PriorityQueue<T>::fixUp(typename BinaryTree<T>::node n)
{
    if (n != BinaryTree<T>::getRoot())
    {
        typename BinaryTree<T>::node p = BinaryTree<T>::getParent(n);
        if (BinaryTree<T>::read(n) < BinaryTree<T>::read(p))
        {
            T temp = BinaryTree<T>::read(n);
            BinaryTree<T>::write(n, BinaryTree<T>::read(p));
            BinaryTree<T>::write(p, temp);
            fixUp(p);
        }
    }
}

#endif
