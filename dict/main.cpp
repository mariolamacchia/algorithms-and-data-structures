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
    Dictionary<int, 4> d1;
    d1.set("first", 16);
    d1.set("first2", 15);
    d1.set("a", 20);
    d1.set("aaa", 21);
    startTest("all 1");
    cout << (d1.get("first") == 16) << ", ";
    cout << (d1.get("first2") == 15) << ", ";
    cout << (d1.get("a") == 20) << ", ";
    cout << (d1.get("aaa") == 21) << ", ";
    endTest();

    cout << "Remove key 'first'\n";
    d1.remove("first");
    cout << "Is there key 'first'?";
    startTest("0");
    cout << d1.has("first");
    endTest();

    cout << "Empty dict\n";
    d1.remove("first2");
    d1.remove("a");
    d1.remove("aaa");
    cout << "Is dict empty?";
    startTest("1");
    cout << d1.isEmpty();
    endTest();
    
    cout << "End";
}
