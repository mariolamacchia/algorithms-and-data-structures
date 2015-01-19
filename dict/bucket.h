#include <iostream>

using namespace std;

template <class T>
class Bucket
{
    public:
        Bucket();
        bool operator==(Bucket);

        void setValue(T v);
        void setKey(string k);
        void clear();

        T getValue() { return value; };
        string getKey() {return key; };

        bool isNew() { return _new; };
        bool isEmpty() { return empty; };
    private:
        string key;
        T value;
        bool _new;
        bool empty;
};

template <class T>
Bucket<T>::Bucket()
{
    _new = true;
    empty = true;
}

template <class T>
bool Bucket<T>::operator==(Bucket b)
{
    return key == b.key;
}

template <class T>
void Bucket<T>::setKey(string k)
{
    key = k;
    _new = false;
    empty = false;
}

template <class T>
void Bucket<T>::setValue(T v)
{
    value = v;
    _new = false;
    empty = false;
}

template <class T>
void Bucket<T>::clear()
{
    empty = true;
}
