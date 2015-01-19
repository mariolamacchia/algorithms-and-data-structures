#ifndef _GRAPH_H
#define _GRAPH_H

#include "node.h"
#include "nodeinfo2.h"
#include "../list/list.h"

template <class T, class W>
class Graph
{
    public:
        typedef Node<T> node;
        
        bool isEmpty() const;
        bool hasNode(node) const;
        bool hasArc(node, node) const;

        W getWeight(node, node) const;
        List<node> getAdjacents(node) const;
        T getValue(node) const;
        
        void insertNode(node);
        void insertArc(node, node, W);

        void removeNode(node);
        void removeArc(node, node);

    private:
        List<NodeInfo<T,W> > nodeList;
};

template <class T, class W>
bool Graph<T, W>::isEmpty() const
{
    return nodeList.isEmpty();
}

template <class T, class W>
bool Graph<T, W>::hasNode(node n) const
{
    typename List<NodeInfo<T,W> >::cell c;
    c = nodeList.getFirst();
    while (!nodeList.eol(c))
    {
        if (nodeList.read(c).getNode() == n) return true;
        c = nodeList.getNext(c);
    }
    return false;
}

template <class T, class W>
bool Graph<T, W>::hasArc(node n1, node n2) const
{
    if (!(hasNode(n1) && hasNode(n2))) return false;
    typename List<NodeInfo<T,W> >::cell c = nodeList.getFirst();
    while (!nodeList.eol(c))
    {
        if (nodeList.read(c).getNode() == n1)
        {
            NodeInfo<T,W> n = nodeList.read(c);
            typename List<ArcInfo<T,W> >::cell c1;
            c1 = n.arcs.getFirst();
            while (!n.arcs.eol(c1))
            {
                if (n.arcs.read(c1).getNode() == n2) return true;
                c1 = n.arcs.getNext(c1);
            }
        }
        c = nodeList.getNext(c);
    }
    return false;
}

template <class T, class W>
W Graph<T, W>::getWeight(node n1, node n2) const
{
    typename List<NodeInfo<T,W> >::cell c = nodeList.getFirst();
    while (!nodeList.eol(c))
    {
        if (nodeList.read(c).getNode() == n1)
        {
            NodeInfo<T,W> n = nodeList.read(c);
            typename List<ArcInfo<T,W> >::cell c1;
            c1 = n.arcs.getFirst();
            while (!n.arcs.eol(c1))
            {
                if (n.arcs.read(c1).getNode() == n2)
                {
                    return n.arcs.read(c1).getWeight();
                }
                c1 = n.arcs.getNext(c1);
            }
        }
        c = nodeList.getNext(c);
    }
    throw;
}

template <class T, class W>
T Graph<T, W>::getValue(node n) const
{
    typename List<NodeInfo<T,W> >::cell c = nodeList.getFirst();
    while (!nodeList.eol(c))
    {
        if (nodeList.read(c).getNode() == n) return n.getValue();
        c = nodeList.getNext(c);
    }
    throw;
}

template <class T, class W>
List<Node<T> > Graph<T, W>::getAdjacents(node n) const
{
    List<Node<T> > list;
    typename List<NodeInfo<T,W> >::cell c = nodeList.getFirst();
    while (!nodeList.eol(c))
    {
        if (nodeList.read(c).getNode() == n)
        {
            NodeInfo<T, W> n1 = nodeList.read(c);
            typename List<ArcInfo<T,W> >::cell c1;
            c1 = n1.arcs.getFirst();
            while (!n1.arcs.eol(c1))
            {
                list.insert(list.getFirst(), n1.arcs.read(c1).getNode());
                c1 = n1.arcs.getNext(c1);
            }
            return list;
        }
        c = nodeList.getNext(c);
    }
    throw;
}

template <class T, class W>
void Graph<T, W>::insertNode(node n)
{
    if (!hasNode(n))
    {
        NodeInfo<T,W> nodeInfo;
        nodeInfo.setNode(n);
        nodeList.insert(nodeList.getFirst(), nodeInfo);
    }
}

template <class T, class W>
void Graph<T, W>::insertArc(node n1, node n2, W weight)
{
    if (!hasArc(n1, n2))
    {
        NodeInfo<T,W> nInfo1, nInfo2;
        typename List<NodeInfo<T,W> >::cell c = nodeList.getFirst();
        while (!nodeList.eol(c))
        {
            if (nodeList.read(c).getNode() == n1)
            {
                NodeInfo<T,W> nInfo = nodeList.read(c);
                ArcInfo<T,W> aInfo;
                aInfo.setWeight(weight);
                aInfo.setNode(n2);
                nInfo1.arcs.insert(nInfo1.arcs.getFirst(), aInfo);
            }
            c = nodeList.getNext(c);
        }
    }
}

template <class T, class W>
void Graph<T, W>::removeArc(node n1, node n2)
{
    if (hasArc(n1, n2))
    {
        typename List<NodeInfo<T,W> >::cell c = nodeList.getFirst();
        while (!nodeList.eol(c))
        {
            if (nodeList.read(c).getNode() == n1)
            {
                NodeInfo<T,W> n = nodeList.read(c);
                typename List<ArcInfo<T,W> >::cell c1;
                c1 = n.arcs.getFirst();
                while (!n.arcs.eol(c1))
                {
                    if (n.arcs.read(c1).getNode() == n2)
                    {
                        n.arcs.remove(c1);
                        return;
                    }
                    c1 = n.arcs.getNext(c1);
                }
            }
            c = nodeList.getNext(c);
        }
    }
}

template <class T, class W>
void Graph<T, W>::removeNode(node n)
{
    if (hasNode(n))
    {
        typename List<NodeInfo<T,W> >::cell c = nodeList.getFirst();
        while (!nodeList.eol(c))
        {
            if (nodeList.read(c).getNode() == n)
            {
                nodeList.remove(c);
                return;
            }
            c = nodeList.getNext(c);
        }
    }
}

#endif
