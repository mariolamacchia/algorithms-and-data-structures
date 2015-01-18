#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

template <class T>
class PriorityQueue
{
    public:
        PriorityQueue();
        ~PriorityQueue();

        void insert(T);
        T read() const;
        T pull();
        bool isEmpty() const;
    private:
        static const int maxLength = 100;
        int length;
        void fixUp(int);
        void fixDown(int);
        T * values;
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    values = new T[maxLength];
    length = 0;
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    delete values;
}

template <class T>
void PriorityQueue<T>::insert(T v)
{
    if (length == maxLength) return;
    values[length++] = v;
    fixUp(length-1);
}

template <class T>
T PriorityQueue<T>::read() const
{
    return values[0];    
}

template <class T>
T PriorityQueue<T>::pull()
{
    T v = read();
    values[0] = values[--length];
    fixDown(0);
    return v;
}

template <class T>
bool PriorityQueue<T>::isEmpty() const
{
    return length == 0;
}

template <class T>
void PriorityQueue<T>::fixDown(int node)
{
    // Check if node is not leaf
    bool hasLeftChild = node * 2 + 1 < length,
         hasRightChild = node * 2 + 2 < length;
    if (hasLeftChild)
    {
        int minIndex = node * 2 + 1;
        if (hasRightChild && values[minIndex] > values[minIndex+1]) minIndex++;
        // Check node is greater than children
        if (values[node] > values[minIndex])
        {
            T temp = values[node];
            values[node] = values[minIndex];
            values[minIndex] = temp;
            fixDown(minIndex);
        }
    }
}

template <class T>
void PriorityQueue<T>::fixUp(int node)
{
    int parentIndex = (node - 1) / 2;
    if (values[node] < values[parentIndex])
    {
        T temp = values[node];
        values[node] = values[parentIndex];
        values[parentIndex] = temp;
        fixUp(parentIndex);
    }
}

#endif
