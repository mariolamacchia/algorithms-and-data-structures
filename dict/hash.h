#include <iostream>

using namespace std;

/* Return the int value of middle 8 bytes of the key */
int hash1(string);

/* Return the int value of the XOR of each char in the string */
int hash2(string);

/* Return the int value if the key % m = 255 */
int hash3(string);

/* Return the int value of middle 8 bytes of a complex operation on key */
int hash4(string);
