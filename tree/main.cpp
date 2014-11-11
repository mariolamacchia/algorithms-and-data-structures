#include <iostream>
#include "tree.h"
#include "traversals.h"

using namespace std;

int main()
{
    Tree<int> *t1, *t2;
    Node<int> *n;

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

    // pre-order print
    printPreOrder(t1);
    // post-order print
    printPostOrder(t1);
    // in-order (2) print
    printInOrder(t1, 2);

    // Remove 3
    t1->remove(t1->getSibling(t1->getChild(t1->getRoot())));

    // pre-order print
    printPreOrder(t1);
    // post-order print
    printPostOrder(t1);
    // in-order (1) print
    printInOrder(t1, 1);

    cout << "End\n";
}
