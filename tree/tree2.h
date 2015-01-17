#ifndef _TREE_H
#define _TREE_H

#include <climits>

template <class T>
class Tree
{
    public:
        typedef int node;
        Tree();
        ~Tree();

        bool isEmpty() const;
        bool isLastChild(int) const;
        bool isLeaf(int) const;

        int getRoot() const;
        int getParent(int) const;
        int getSibling(int) const;
        int getChild(int) const;

        void insert(int, int, Tree<T>*);
        void remove(int);
        void setRoot(T);

        T read(int) const;
        void write(int, T);
    private:
        void create();
        int freeNextCell(int cell);
        void copySubtree(Tree<T>*, int, int);
        static const int maxLength = 100;
        static const int empty = INT_MAX - 1;
        static const int undefined = INT_MAX;
        typedef struct {
            int parent;
            T value;
        } nodeCell;
        nodeCell* values;
};

template <class T>
Tree<T>::Tree()
{
    create();
}

template <class T>
Tree<T>::~Tree()
{
    delete values;
}

template <class T>
bool Tree<T>::isEmpty() const
{
    return read(getRoot()) == undefined;
}

template <class T>
bool Tree<T>::isLastChild(int n) const
{
    for (int i = n + 1; i < maxLength; i++)
    {
        if (getParent(i) == getParent(n)) return false;
    }
    return true;
}

template <class T>
bool Tree<T>::isLeaf(int n) const
{
    for (int i = 0; i < maxLength; i++)
    {
        if (getParent(i) == n) return false;
    }
    return true;
}

template <class T>
int Tree<T>::getRoot() const
{
    return 0;
}

template <class T>
int Tree<T>::getParent(int n) const
{
    return values[n].parent;
}

template <class T>
int Tree<T>::getSibling(int n) const
{
    for (int i = n+1; i < maxLength; i++)
    {
        if (getParent(i) == getParent(n)) return i;
    }
    return -1;
}

template <class T>
int Tree<T>::getChild(int n) const
{
    for (int i = n; i < maxLength; i++)
    {
        if (getParent(i) == n) return i;
    }
    return -1;
}

template <class T>
void Tree<T>::insert(int np, int ns, Tree<T>* t)
{
    // Allocate cell after to ns
    int nn = freeNextCell(ns);
    values[nn].parent = np;

    // Copy t as subtree with allocated cell as root
    copySubtree(t, t->getRoot(), nn);
}

template <class T>
void Tree<T>::copySubtree(Tree<T>* source, int sourceNode, int destNode)
{
    // remove subtree with destNode as root
    int parent = getParent(destNode);
    remove(destNode);
    values[destNode].parent = parent;

    // set destNode value as source's root
    write(destNode, source->read(sourceNode));

    // insert descendant
    sourceNode = source->getChild(sourceNode);
    int childNode = destNode;
    while (sourceNode != -1)
    {
        childNode = freeNextCell(childNode);
        values[childNode].parent = destNode;
        copySubtree(source, sourceNode, childNode);
        sourceNode = source->getSibling(sourceNode);
    }
}

template <class T>
void Tree<T>::remove(int n)
{
    while (!isLeaf(n)) remove(getChild(n));
    values[n].value = undefined;
    values[n].parent = -1;
}

template <class T>
void Tree<T>::setRoot(T v)
{
    write(getRoot(), v);
}

template <class T>
void Tree<T>::create()
{
    values = new nodeCell[maxLength];
    for (int i = 0; i < maxLength; i++)
    {
        values[i].parent = -1;
        values[i].value = undefined;
    }
}

template <class T>
T Tree<T>::read(int n) const
{
    return values[n].value;
}

template <class T>
void Tree<T>::write(int n, T v)
{
    values[n].value = v;
}

template <class T>
int Tree<T>::freeNextCell(int cell)
{
    cell++;
    // shift all the array and get free cell
    for (int i = maxLength - 1; i > cell; i--)
    {
        if (values[i-1].value != undefined)
        {
            values[i].parent = values[i-1].parent;
            values[i].value = values[i-1].value;
            /*
               All cells after cell will be shifted,
               so all parents with value >= cell will be
               incremented by 1
            */
            if (values[i].parent >= cell) values[i].parent++;
        }
    }
    return cell;
}

#endif
