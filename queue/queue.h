#ifndef _QUEUE_H
#define _QUEUE_H

template <class T, int MAX>
class Queue
{
    public:
        Queue();
        Queue(Queue<T, MAX> &);

        T read() const;
        T pop();
        void push(T);
        bool isEmpty() const;

    private:
        void create();

        T queue[MAX];
        int length;
        T ERROR_VALUE;
};

template <class T, int MAX>
Queue<T, MAX>::Queue()
{
}

template <class T, int MAX>
Queue<T, MAX>::Queue(Queue<T, MAX> & q)
{
}

template <class T, int MAX>
void Queue<T, MAX>::create()
{
}

template <class T, int MAX>
T Queue<T, MAX>::read() const
{
}

template <class T, int MAX>
T Queue<T, MAX>::pop()
{
    return 0;
}

template <class T, int MAX>
void Queue<T, MAX>::push(T v)
{
}

template <class T, int MAX>
bool Queue<T, MAX>::isEmpty() const
{
    return true;
}

#endif
