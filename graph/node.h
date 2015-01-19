#ifndef _NODE_H
#define _NODE_H

template <class T>
class Node
{
    public:
        Node() {id = -1;};
        Node(T v) { value = v; id = -1; };
        T getValue() { return value; };
        void setValue(T v) { value = v; };

        bool operator==(Node n) { return n.getValue() == value; };
        void operator=(Node n) { id = n.id; value = n.value; };

        // Needed for matrix graph
        int id;
    private:
        T value;
};

#endif
