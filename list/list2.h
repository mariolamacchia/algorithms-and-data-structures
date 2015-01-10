#ifndef _LIST_H
#define _LIST_H

#define DEF_LENGTH 100

template <class T>
class List
{
    public:
        typedef int cell;

        List();
        List(const List&);
        ~List();

        void createList(int);

        bool eol(int) const;
        bool isEmpty() const;

        int getFirst() const;
        int getNext(int) const;
        int getPrevious(int) const;

        T read(int) const;
        void write(int, T);

        void insert(int, T);
        void remove(int);
    private:
        int length;
        int maxLength;
        T* values;
};

template <class T>
List<T>::List()
{
    createList(DEF_LENGTH);
}

template <class T>
List<T>::List(const List & l)
{
    int c1, c2;
    createList(DEF_LENGTH);
    c1 = l.getFirst();
    c2 = getFirst();
    while (!l.eol(c1))
    {
        insert(c2, l.read(c1));
        c1 = l.getNext(c1);
    }
}

template <class T>
List<T>::~List()
{
    int c;
    while (!isEmpty())
    {
        remove(getFirst());
    }
    delete values;
}


template <class T>
void List<T>::createList(int mlength)
{
    values = new T[mlength];
    maxLength = mlength;
    length = 0;
}

template <class T>
bool List<T>::eol(int c) const
{
    return c == length;
}


template <class T>
bool List<T>::isEmpty() const
{
    return eol(getFirst());
}


template <class T>
int List<T>::getFirst() const
{
    return 0;
}


template <class T>
int List<T>::getNext(int c) const
{
    if (!eol(c)) return c+1;
    return 0;
}


template <class T>
int List<T>::getPrevious(int c) const
{
    if (c > 0) return c-1;
    return length;
}


template <class T>
T List<T>::read(int c) const
{
    return values[c];
}


template <class T>
void List<T>::write(int c, T v)
{
    values[c] = v;
}


template <class T>
void List<T>::insert(int c, T v)
{
    if (length == maxLength) return;
    int d = length;
    while (d != c)
    {
        values[d] = values[d-1];
        d--;
    }
    values[c] = v;
    length++;
}


template <class T>
void List<T>::remove(int c)
{
    int d = c;
    while (d != length-1) {
        values[d] = values[d+1];
        d++;
    }
    length--;
}


#endif
