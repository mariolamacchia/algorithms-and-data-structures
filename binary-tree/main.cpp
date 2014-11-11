#include <iostream>
#include "binary-tree.h"
#include "trasversals.h"

using namespace std;

int main()
{
    BinaryTree<int> * t1, * t2, * t3;

    cout << "Create empty tree\n";
    t1 = new BinaryTree<int>;
    cout << "Is tree empty? " << t1->isEmpty() << "\n";

    cout << "       1\n";
    cout << "      / \\\n";
    cout << "     2   3\n";
    cout << "    /|  / \\\n";
    cout << "   4 5 6   7\n";
    cout << "    / \\    \\\n";
    cout << "   8   9    10\n";

    t2 = new BinaryTree<int>;
    t1->setRoot(8);
    t2->setRoot(9);
    t2 = new BinaryTree<int>(t1, t2);
    t2->setRoot(5);
    t1 = new BinaryTree<int>;
    t1->setRoot(4);
    t1 = new BinaryTree<int>(t1, t2);
    t1->setRoot(2);
    t3 = new BinaryTree<int>;
    t3->setRoot(10);
    t2 = new BinaryTree<int>;
    t3 = new BinaryTree<int>(t2, t3);
    t3->setRoot(7);
    t2 = new BinaryTree<int>;
    t2->setRoot(6);
    t2 = new BinaryTree<int>(t2, t3);
    t2->setRoot(3);
    t1 = new BinaryTree<int>(t1, t2);
    t1->setRoot(1);

    // print
    printPreOrder(t1);
    printPostOrder(t1);
    printInOrder(t1);

    cout << "Remove 3\n";
    t1->removeRightChild(t1->getRoot());

    // print
    printPreOrder(t1);
    printPostOrder(t1);
    printInOrder(t1);

    cout << "End\n";
}
