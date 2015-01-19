#ifndef _NODE_INFO
#define _NODE_INFO

#include "arcinfo1.h"

template <class T, class W>
class NodeInfo
{
    public:
        NodeInfo() {empty = true;};
        void setValue(T v) {value = v; empty = false;};
        void clear() {empty = true;};
        bool isEmpty() {return empty;};
        T getValue() {return value;};
        ArcInfo<W>* arcs;
    private:
        T value;
        bool empty; 
};

#endif
