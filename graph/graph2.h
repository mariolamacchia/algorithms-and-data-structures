#ifndef _GRAPH_H
#define _GRAPH_H

#include "node.h"
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
        List<node>* getAdjacents(node) const;
        
        void insertNode(node);
        void insertArc(node, node, W);

        void removeNode(node);
        void removeArc(node, node);
};

template <class T, class W>
Graph<T, W>::Graph() {}

template <class T, class W>
bool Graph<T, W>::isEmpty() const {return false;}

template <class T, class W>
bool Graph<T, W>::hasNode(node n) const {return false;}

template <class T, class W>
bool Graph<T, W>::hasArc(node n1, node n2) const {return false;}

template <class T, class W>
W Graph<T, W>::getWeight(node n1, node n2) const {return 0;}

template <class T, class W>
T Graph<T, W>::getValue(node n) const {return 0;}

template <class T, class W>
List<Node<T> >* Graph<T, W>::getAdjacents(node n1) const
{
    return new List<Node<T> >;
}

template <class T, class W>
void Graph<T, W>::insertNode(node n){}

template <class T, class W>
void Graph<T, W>::insertArc(node n1, node n2, W weight) {}

template <class T, class W>
void Graph<T, W>::removeArc(node n1, node n2) {}

template <class T, class W>
void Graph<T, W>::removeNode(node n) {}

#endif
