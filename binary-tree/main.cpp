#include <iostream>
#include "binary-tree.h"
#include "trasversals.h"
#include "../tests.h"

using namespace std;

int main()
{
    BinaryTree<int> * t1, * t2, * t3;

    cout << "Create empty tree\n";
    t1 = new BinaryTree<int>;
    cout << "Is tree empty? ";
    startTest("1");
    cout << t1->isEmpty();
    endTest();

    cout << "       1\n";
    cout << "      / \\\n";
    cout << "     2   3\n";
    cout << "    /|  / \\\n";
    cout << "   4 5 6   7\n";
    cout << "    / \\    \\\n";
    cout << "   8   9    10\n\n\n";

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
    cout << "Pre-order";
    startTest("[4, 8, 9, 5, 2, 6, 10, 7, 3, 1, ]");
    printPreOrder(t1);
    endTest();
    cout << "Post-order";
    startTest("[1, 2, 4, 5, 8, 9, 3, 6, 7, 10, ]");
    printPostOrder(t1);
    endTest();
    cout << "In-order";
    startTest("[4, 2, 8, 5, 9, 1, 6, 3, 7, 10, ]");
    printInOrder(t1);
    endTest();

    cout << "Remove 3\n";
    t1->removeRightChild(t1->getRoot());

    // print
    cout << "Pre-order";
    startTest("[4, 8, 9, 5, 2, 1, ]");
    printPreOrder(t1);
    endTest();
    cout << "Post-order";
    startTest("[1, 2, 4, 5, 8, 9, ]");
    printPostOrder(t1);
    endTest();
    cout << "In-order";
    startTest("[4, 2, 8, 5, 9, 1, ]");
    printInOrder(t1);
    endTest();

    cout << "End\n";
}
