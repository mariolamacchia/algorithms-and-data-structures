#ifndef _NODE_H
#define _NODE_H

template <class T>
class Node
{
    public:
        Node() {}
        Node(T v) { value = v; };
        T getValue() { return value; };
        void setValue(T v) { value = v; };

        bool operator==(Node n) { return n.getValue() == value; };
    private:
        T value;
};

#endif
