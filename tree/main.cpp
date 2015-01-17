#include <iostream>
#include "tree.h"
#include "traversals.h"
#include "../tests.h"

using namespace std;

int main()
{
    Tree<int> *t1, *t2;
    typename Tree<int>::node n;

    cout << "    1\n";
    cout << "   / \\\n";
    cout << "  2   3\n";
    cout << " / \\ /|\\\n";
    cout << "4  5 678\n";
    cout << "      |\n";
    cout << "      9\n";

    t1 = new Tree<int>();
    t2 = new Tree<int>();

    t1 = new Tree<int>();
    t1->setRoot(3);
    t2 = new Tree<int>();
    t2->setRoot(7);
    t1->insert(t1->getRoot(),
               t1->getRoot(),
               t2);
    t2 = new Tree<int>();
    t2->setRoot(8);
    t1->insert(t1->getRoot(),
               t1->getChild(t1->getRoot()),
               t2);
    t2 = new Tree<int>();
    t2->setRoot(6);
    t1->insert(t1->getRoot(),
               t1->getRoot(),
               t2);
    t2 = new Tree<int>();
    t2->setRoot(1);
    t2->insert(t2->getRoot(),
               t2->getRoot(),
               t1);
    t1 = t2;
    t2 = new Tree<int>();
    t2->setRoot(2);
    t1->insert(t1->getRoot(),
               t1->getRoot(),
               t2);
    t2 = new Tree<int>();
    t2->setRoot(4);
    t1->insert(t1->getChild(t1->getRoot()),
               t1->getChild(t1->getRoot()),
               t2);
    t2 = new Tree<int>();
    t2->setRoot(5);
    t1->insert(t1->getChild(t1->getRoot()),
               t1->getChild(t1->getChild(t1->getRoot())),
               t2);
    t2 = new Tree<int>();
    t2->setRoot(9);
    n = t1->getRoot();
    n = t1->getChild(n);
    n = t1->getSibling(n);
    n = t1->getChild(n);
    n = t1->getSibling(n);
    t1->insert(n, n, t2);                

    cout << "Pre-order";
    startTest("[4, 5, 2, 6, 9, 7, 8, 3, 1, ]");
    printPreOrder(t1);
    endTest();

    cout << "Post-order";
    startTest("[1, 2, 4, 5, 3, 6, 7, 9, 8, ]");
    printPostOrder(t1);
    endTest();

    cout << "In-order (2)";
    startTest("[4, 5, 2, 6, 9, 7, 3, 8, 1, ]");
    printInOrder(t1, 2);
    endTest();

    cout << "Remove 3\n";
    t1->remove(t1->getSibling(t1->getChild(t1->getRoot())));

    cout << "Pre-order";
    startTest("[4, 5, 2, 1, ]");
    printPreOrder(t1);
    endTest();

    cout << "Post-order";
    startTest("[1, 2, 4, 5, ]");
    printPostOrder(t1);
    endTest();

    cout << "In-order (1)";
    startTest("[4, 2, 5, 1, ]");
    printInOrder(t1, 1);
    endTest();

    cout << "Remove 1\n";
    t1->remove(t1->getRoot());
    cout << "Is empty? ";
    startTest("1");
    cout << t1->isEmpty();
    endTest();

    cout << "End\n";
}
