#ifndef _ARC_INFO_H
#define _ARC_INFO_H

template <class W>
class ArcInfo
{
    public:
        ArcInfo() {empty = true;};
        W getWeight() {return weight;};
        void setWeight(W v) {weight = v; empty = false;};
        bool isEmpty() {return empty;};
        void clear() {empty = true;};
    private:
        W weight;
        bool empty;
};

#endif
