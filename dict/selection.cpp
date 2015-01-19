#include "selection.h"

int selectQuadratic(int hash, int i, int m)
{
    return (hash + i * (i-1) / 2) % m;
}

int selectDoubleHash(int hash1, int hash2, int i, int m)
{
    return (hash1 + i * hash2) % m;
}
