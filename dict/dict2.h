#include <climits>
#include <iostream>
#include "bucket.h"
#include "hash.h"
#include "selection.h"

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
        int select(string, int) const;
        Bucket<T> * table;
};

template <class T, int maxLength>
Dictionary<T, maxLength>::Dictionary()
{
    table = new Bucket<T>[maxLength];
}

template <class T, int maxLength>
Dictionary<T, maxLength>::~Dictionary()
{
    //delete table;
}

template <class T, int maxLength>
bool Dictionary<T, maxLength>::has(string key) const
{
    int i = 0;
    while (i < maxLength)
    {
        int index = select(key, i);
        if (table[index].isNew()) return false;
        if (table[index].getKey() == key && !table[index].isEmpty())
        {
            return true;
        }
        i++;
    }
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
    int i = 0;
    while (i < maxLength)
    {
        int index = select(key, i);
        if (table[index].isNew()) throw;
        if (table[index].getKey() == key) return table[index].getValue();
        i++;
    }
    throw;
}

template <class T, int maxLength>
void Dictionary<T, maxLength>::set(string key, T value)
{
    if (has(key))
    {
        int i = 0;
        while (table[select(key, i)].getKey() != key) i++;
        table[select(key, i)].setValue(value);
    }
    else
    {
        int i = 0;
        while (!table[select(key, i)].isEmpty() && i < maxLength) i++;
        // Throw error if structure is full
        if (i == maxLength) throw;
        table[select(key, i)].setKey(key);
        table[select(key, i)].setValue(value);
    }
}

template <class T, int maxLength>
void Dictionary<T, maxLength>::remove(string key)
{
    int i = 0;
    while (i < maxLength)
    {
        int index = select(key, i);

        // Throw if key does not exist
        if (table[index].isNew()) throw;

        // Remove key
        if (table[index].getKey() == key) return table[index].clear();

        i++;
    }

    // Throw if key does not exist
    throw;
}

template <class T, int maxLength>
int Dictionary<T, maxLength>::select(string key, int i) const
{
    return selectQuadratic(hash2(key), i, maxLength);
}
