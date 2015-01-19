#ifndef _ARC_INFO_H
#define _ARC_INFO_H

#include "nodeinfo2.h"

template <class T, class W>
class ArcInfo
{
    public:
        W getWeight() {return weight;};
        void setWeight(W w) {weight = w;};
        void setNode(Node<T>& n) {node = n;};
        Node<T>& getNode() {return node;};

        bool operator==(ArcInfo a) {return node == a.node && weight == a.weight;}
    private:
        W weight;
        Node<T> node;
};

#endif
