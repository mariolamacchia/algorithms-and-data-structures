#include <iostream>

using namespace std;

template <class T>
class Bucket
{
    public:
        Bucket();
        bool operator==(Bucket);

        void setValue(T v) { value = v; };
        void setKey(string k) { key = k; };

        T getValue() { return value; };
        string getKey() {return key; };
    private:
        string key;
        T value;
};

template <class T>
Bucket<T>::Bucket()
{
}

template <class T>
bool Bucket<T>::operator==(Bucket b)
{
    return key == b.key;
}
