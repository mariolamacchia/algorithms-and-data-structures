#include <iostream>
#include "dict.h"
#include "../tests.h"

int main()
{
    cout << "Create empty dicionary" << endl;
    Dictionary<int, 100> d;

    cout << "Is it empty?";
    startTest("1");
    cout << d.isEmpty();
    endTest();

    cout << "Has it key 'first'?";
    startTest("0");
    cout << d.has("first");
    endTest();

    cout << "Set first" << endl;
    d.set("first", 15);

    cout << "Has it key 'first'?";
    startTest("1");
    cout << d.has("first");
    endTest();

    cout << "Get key 'first'";
    startTest("15");
    cout << d.get("first");
    endTest();

    cout << "Edit key";
    d.set("first", 16);
    startTest("16");
    cout << d.get("first");
    endTest();

    cout << "Test collisions";
    d.set("first", 15);
    d.set("first1", 16);
    d.set("first2", 17);
    d.set("a", 20);
    d.set("aa", 21);
    d.set("aaa", 22);
    d.set("aaaa", 23);
    d.set("aaaaa", 24);
    startTest("all 1");
    cout << (d.get("first") == 15) << ", ";
    cout << (d.get("first1") == 16) << ", ";
    cout << (d.get("first2") == 17) << ", ";
    cout << (d.get("a") == 20) << ", ";
    cout << (d.get("aa") == 21) << ", ";
    cout << (d.get("aaa") == 22) << ", ";
    cout << (d.get("aaaa") == 23) << ", ";
    cout << (d.get("aaaaa") == 24) << ", ";
    endTest();

    cout << "Remove key 'first'\n";
    d.remove("first");
    cout << "Is there key 'first'?";
    startTest("0");
    cout << d.has("first");
    endTest();

    cout << "Empty dict\n";
    d.remove("first1");
    d.remove("first2");
    d.remove("a");
    d.remove("aa");
    d.remove("aaa");
    d.remove("aaaa");
    d.remove("aaaaa");
    cout << "Is dict empty?";
    startTest("1");
    cout << d.isEmpty();
    endTest();
    
    cout << "End";
}
