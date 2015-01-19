#ifndef _GRAPH_H
#define _GRAPH_H

#include "node.h"
#include "nodeinfo.h"
#include "../list/list.h"

template <class T, class W>
class Graph
{
    public:
        typedef Node<T> node;

        Graph();

        bool isEmpty() const;
        bool hasNode(node) const;
        bool hasArc(node, node) const;

        W getWeight(node, node) const;
        T getValue(node) const;
        List<node> getAdjacents(node) const;

        void insertNode(node&);
        void insertArc(node, node, W);

        void removeNode(node);
        void removeArc(node, node);

    private:
        static const int dimension = 100;
        NodeInfo<T,W>* matrix;
};

template <class T, class W>
Graph<T, W>::Graph()
{
    matrix = new NodeInfo<T,W>[dimension];
    for (int i = 0; i < dimension; i++)
    {
        matrix[i].arcs = new ArcInfo<W>[dimension];
    }
}

template <class T, class W>
bool Graph<T, W>::isEmpty() const
{
    for (int i = 0; i < dimension; i++)
    {
        if (!matrix[i].isEmpty()) return false;
    }
    return true;
}

template <class T, class W>
bool Graph<T, W>::hasNode(node n) const
{
    return (n.id != -1 && !matrix[n.id].isEmpty());
}

template <class T, class W>
bool Graph<T, W>::hasArc(node n1, node n2) const
{
    if (!(hasNode(n1) && hasNode(n2))) return false;
    return !matrix[n1.id].arcs[n2.id].isEmpty();
}

template <class T, class W>
T Graph<T, W>::getValue(node n) const
{
    return matrix[n.id].getValue();
}

template <class T, class W>
W Graph<T, W>::getWeight(node n1, node n2) const
{
    return matrix[n1.id].arcs[n2.id].getWeight();
}

template <class T, class W>
List<Node<T> > Graph<T, W>::getAdjacents(node n) const
{
    List<Node<T> > l;
    for (int i = 0; i < dimension; i++)
    {
        if (!matrix[n.id].arcs[i].isEmpty())
        {
            Node<T> n(matrix[i].getValue());
            n.id = i;
            l.insert(l.getFirst(), n);
        }
    }
    return l;
}

template <class T, class W>
void Graph<T, W>::insertNode(node& n)
{
    for (int i = 0; i < dimension; i++)
    {
        if (matrix[i].isEmpty())
        {
            matrix[i].setValue(n.getValue());
            n.id = i;
            return;
        }
    }
    // Throw error if graph is full
    throw;
}

template <class T, class W>
void Graph<T, W>::insertArc(node n1, node n2, W weight)
{
    matrix[n1.id].arcs[n2.id].setWeight(weight);
}

template <class T, class W>
void Graph<T, W>::removeArc(node n1, node n2)
{
    matrix[n1.id].arcs[n2.id].clear();
}

template <class T, class W>
void Graph<T, W>::removeNode(node n)
{
    matrix[n.id].clear();
}

#endif
