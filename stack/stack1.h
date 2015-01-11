#ifndef _STACK_H
#define _STACK_H

template <class T, int MAX>
class Stack
{
    public:
        Stack();
        Stack(Stack<T, MAX> &);

        T read() const;
        T pop();
        void push(T);
        bool isEmpty() const;

    private:
        void create();

        T stack[MAX];
        int length;
        T ERROR_VALUE;
};

template <class T, int MAX>
Stack<T, MAX>::Stack()
{
    create();
}

template <class T, int MAX>
Stack<T, MAX>::Stack(Stack<T, MAX> & s)
{
    create();
    Stack s1;
    T v;
    while (!s.isEmpty())
    {
        s1.push(s.pop());
    }

    while (!s1.isEmpty())
    {
        v = s1.pop();
        push(v);
        s.push(v);
    }
}

template <class T, int MAX>
void Stack<T, MAX>::create()
{
    length = 0;
}

template <class T, int MAX>
T Stack<T, MAX>::read() const
{
    if (isEmpty()) return ERROR_VALUE;
    return stack[length - 1];
}

template <class T, int MAX>
T Stack<T, MAX>::pop()
{
    if (isEmpty()) return ERROR_VALUE;
    length--;
    return stack[length];
}

template <class T, int MAX>
void Stack<T, MAX>::push(T v)
{
    if (length == MAX) return;
    stack[length] = v;
    length++;
}

template <class T, int MAX>
bool Stack<T, MAX>::isEmpty() const
{
    return length == 0;
}

#endif
