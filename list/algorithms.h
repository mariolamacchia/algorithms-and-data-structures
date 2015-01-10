#include "list.h"

template <class T>
int searchOrdered(List<T>* l, T value)
{
    /*
       If found, return the position of value,
       else return a negative number indicating
       the number of attempts done
    */
    int ret = 1;
    typename List<T>::cell c = l->getFirst();
    while (!l->eol(c) && l->read(c) <= value)
    {
        if (value == l->read(c)) return ret - 1;
        c = l->getNext(c);
        ret++;
    }
    return ret * -1;
}

template <class T>
int search(List<T>* l, T value)
{
    /*
       If found, return the position of value,
       else return a negative number indicating
       the number of attempts done
    */
    int ret = 1;
    typename List<T>::cell c = l->getFirst();
    while (!l->eol(c))
    {
        if (value == l->read(c)) return ret - 1;
        c = l->getNext(c);
        ret++;
    }
    return ret * -1;
}

template <class T>
List<T>* mergeSort(List<T>* l)
{
    if (!isSorted(l))
    {
        List<T> * l1 = new List<T>,
                * l2 = new List<T>;
        split(l, l1, l2);
        l = mergeOrderedLists(mergeSort(l1), mergeSort(l2));
    }
    return l;
}

template <class T>
bool isSorted(List<T>* l)
{
    typename List<T>::cell c = l->getFirst();
    T min = l->read(c);
    while (!l->eol(c))
    {
        if (l->read(c) < min) return false;
        c = l->getNext(c);
    }
    return true;
}

template <class T>
void split(List<T>* in, List<T>* out1, List<T>* out2)
{
    typename List<T>::cell c = in->getFirst(),
            c1 = out1->getFirst(),
            c2 = out2->getFirst();

    while (!in->eol(c))
    {
        out1->insert(c1, in->read(c));
        c = in->getNext(c);
        if (!in->eol(c))
        {
            out2->insert(c2, in->read(c));
            c = in->getNext(c);
        }
    }

    // empty memory
    delete in;
}

template <class T>
List<T>* mergeOrderedLists(List<T>* l1, List<T>* l2)
{
    List<T> * l = new List<T>;
    typename List<T>::cell c = l->getFirst(),
            c1 = l1->getFirst(),
            c2 = l2->getFirst();

    while (!(l1->eol(c1) && l2->eol(c2)))
    {
        if (l1->read(c1) < l2->read(c2))
        {
            l->insert(c, l1->read(c1));
            c1 = l1->getNext(c1);
        }
        else
        {
            l->insert(c, l2->read(c2));
            c2 = l2->getNext(c2);
        }
        if (l1->eol(c1))
        {
            while (!l2->eol(c2))
            {
                l->insert(c, l2->read(c2));
                c2 = l2->getNext(c2);
            }
        }
        else if (l2->eol(c2))
        {
            while (!l1->eol(c1))
            {
                l->insert(c, l1->read(c1));
                c1 = l1->getNext(c1);
            }
        }
    }
    return l;
}
