#include <climits>
#include <iostream>
#include "../list/list.h"
#include "bucket.h"
#include "hash.h"

using namespace std;

template <class T, int maxLength>
class Dictionary
{
    public:
        Dictionary();
        ~Dictionary();

        bool has(string) const;
        bool isEmpty() const;
        T get(string) const;
        void set(string, T);
        void remove(string);
    private:
        int hash(string) const;
        List<Bucket<T> > * table;
};

template <class T, int maxLength>
Dictionary<T, maxLength>::Dictionary()
{
    table = new List<Bucket<T> >[maxLength];
}

template <class T, int maxLength>
Dictionary<T, maxLength>::~Dictionary()
{
    //delete table;
}

template <class T, int maxLength>
bool Dictionary<T, maxLength>::has(string key) const
{
    int h = hash(key);
    typename List<Bucket<T> >::cell c = table[h].getFirst();
    while (!table[h].eol(c) && table[h].read(c).getKey() != key)
    {
        c = table[h].getNext(c);
    }
    if (table[h].read(c).getKey() == key) return true;
    return false;
}

template <class T, int maxLength>
bool Dictionary<T, maxLength>::isEmpty() const
{
    for (int i = 0; i < maxLength; i++)
    {
        if (!table[i].isEmpty()) return false;
    }
    return true;
}

template <class T, int maxLength>
T Dictionary<T, maxLength>::get(string key) const
{
    int h = hash(key);
    typename List<Bucket<T> >::cell c = table[h].getFirst();
    while (!table[h].eol(c) && table[h].read(c).getKey() != key)
    {
        c = table[h].getNext(c);
    }
    if (table[h].read(c).getKey() == key) return table[h].read(c).getValue();
    throw;
}

template <class T, int maxLength>
void Dictionary<T, maxLength>::set(string key, T value)
{
    int h = hash(key);
    typename List<Bucket<T> >::cell c = table[h].getFirst();
    while (!table[h].eol(c) && table[h].read(c).getKey() != key)
    {
        c = table[h].getNext(c);
    }
    if (table[h].read(c).getKey() == key) table[h].read(c).setValue(value);
    Bucket<T> b;
    b.setKey(key);
    b.setValue(value);
    table[h].insert(c, b);
}

template <class T, int maxLength>
void Dictionary<T, maxLength>::remove(string key)
{
    int h = hash(key);
    typename List<Bucket<T> >::cell c = table[h].getFirst();
    while (!table[h].eol(c) && table[h].read(c).getKey() != key) c = table[h].getNext(c);
    if (table[h].read(c).getKey() == key) table[h].remove(c);
}

template <class T, int maxLength>
int Dictionary<T, maxLength>::hash(string key) const
{
    return hash1(key) % maxLength;
}
