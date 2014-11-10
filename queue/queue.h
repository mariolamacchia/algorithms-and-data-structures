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
        int head;
        T ERROR_VALUE;
};

template <class T, int MAX>
Queue<T, MAX>::Queue()
{
    create();
}

template <class T, int MAX>
Queue<T, MAX>::Queue(Queue<T, MAX> & q)
{
    T v;
    Queue<T, MAX> qt;
    create();

    while (!q.isEmpty())
    {
        qt.push(q.pop());
    }

    while (!qt.isEmpty())
    {
        v = qt.pop();
        q.push(v);
        push(v);
    }
}

template <class T, int MAX>
void Queue<T, MAX>::create()
{
    head = 0;
    length = 0;
}

template <class T, int MAX>
T Queue<T, MAX>::read() const
{
    if (!length) return ERROR_VALUE;
    return queue[head];
}

template <class T, int MAX>
T Queue<T, MAX>::pop()
{
    T v;
    if (!length) return ERROR_VALUE;
    length--;
    v = queue[head];
    head = (head + 1) % MAX;
    return v;
}

template <class T, int MAX>
void Queue<T, MAX>::push(T v)
{
    if (length == MAX) return;
    queue[(head + length) % MAX] = v;
    length++;
}

template <class T, int MAX>
bool Queue<T, MAX>::isEmpty() const
{
    return length == 0;
}

#endif
