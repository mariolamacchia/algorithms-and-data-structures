#include "set.h"

Set::Set()
{
    for (int i = 0; i < maxLength; i++) values[i] = false;
}

bool Set::isEmpty() const
{
    for (int i = 0; i < maxLength; i++)
    {
        if (values[i]) return false;
    }
    return true;
}

int Set::getFirst() const
{
    return getNext(-1);
}

int Set::getNext(int c) const
{
    for (int i = c+1; i < maxLength; i++)
    {
        if (values[i]) return i;
    }
    return -1;
}

int Set::read(int c) const
{
    return c;
}

bool Set::isEndOfSet(int c) const
{
    return c == -1;
}

bool Set::has(int v) const
{
    return values[v];
}

void Set::insert(int v)
{
    values[v] = true;
}

void Set::remove(int v)
{
    values[v] = false;
}
