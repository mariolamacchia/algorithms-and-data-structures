#ifndef _NODE_INFO
#define _NODE_INFO

#include "arcinfo2.h"
#include "../list/list.h"

template <class T, class W>
class NodeInfo
{
    public:
        void setNode(Node<T>& n) {node = n;};
        Node<T>& getNode() {return node;};
        List<ArcInfo<T,W> > arcs;

        bool operator==(NodeInfo n) {return node == n.node;};
    private:
        Node<T> node;
};

#endif
