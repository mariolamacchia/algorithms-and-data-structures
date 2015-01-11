#include <iostream>
#include "stack.h"
#include "algorithms.h"

#define MAX_LENGTH 100

using namespace std;

bool isPalindrome(string a)
{
    Stack<char, MAX_LENGTH>* s = new Stack<char, MAX_LENGTH>;
    int length = a.length();
    for (int i = 0; i < length; i++)
    {
        s->push(a[i]);
    }
    int i = 0;
    while (!s->isEmpty())
    {
        if (a[i++] != s->pop()) return false;
    }
    return true;
}
