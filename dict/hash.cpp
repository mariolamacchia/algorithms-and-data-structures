#include "hash.h"

int hash1(string key)
{
    /* Return the int value of the half 8 bytes of the key */

    // Add space char if key length minor than 6
    while (key.size() < 4) key += " ";

    // Cut string if length greater than 6
    key = key.substr(3,2);

    // Get the half 8 bytes of key
    bitset<16> binValue(key[0]);
    binValue = binValue << 8;
    binValue |= bitset<16>(key[1]);
    binValue = binValue >> 4;
    binValue &= 0xff;

    return binValue.to_ulong();
}

int hash2(string key)
{
    /* Return the int value of the XOR of each char in the string */

    bitset<8> binValue(0);
    for (int i = 0; i < key.size(); i++) binValue ^= bitset<8>(key[i]);

    return binValue.to_ulong();
}

int hash3(string key)
{
    /* Return the int value if the key % m = 255 */

    // Add space char if key size smaller than 6
    while (key.size() < 6) key += " ";

    bitset<48>binValue(0);
    for (int i = 0; i < 6; i++)
    {
        binValue = binValue << 8;
        binValue |= bitset<48>(key[i]);
    }

    return binValue.to_ulong() % 255;
}

int hash4(string key)
{
    /* Return the int value of middle 8 bytes of a complex operation on key */
    
    // get the int value of key
    unsigned long long v = 0;
    for (int i = 0; i < key.size() && i < 6; i++)
    {
        v *= 256;
        v += key[i];
    }
    v = v * v;

    const int bits = sizeof(v) * 8;
    bitset<bits> binValue = bitset<bits>(v);
    binValue = binValue >> (bits/2-4);
    binValue &= 0xff;

    return binValue.to_ulong();
}
