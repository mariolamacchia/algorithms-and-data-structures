#ifndef _ALGORITHMS_H
#define _ALGORITHMS_H

#include "priority-queue.h"

template <class T>
void heapSort(T* values, int size)
{
    PriorityQueue<T> p;
    for (int i = 0; i < size; i++)
    {
        p.insert(values[i]);
    }
    for (int i = 0; i < size; i++)
    {
        values[i] = p.pull();
    }
}

#endif
