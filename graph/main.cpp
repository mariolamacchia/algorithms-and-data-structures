#include <iostream>
#include "graph.h"
#include "../list/list.h"
#include "../tests.h"

using namespace std;

int main()
{
    typedef typename Graph<char, int>::node Node;

    cout << "Create empty graph\n";
    Graph<char, int> g;
    cout << "Is it empty?";
    startTest("1");
    cout << g.isEmpty();
    endTest();

    cout << "Insert nodes A, B\n";
    Node nA('A');
    Node nB('B');
    Node nC('C');
    g.insertNode(nA);
    g.insertNode(nB);

    cout << "Does it have nodes A, B, and C?";
    startTest("1, 1, 0");
    cout << g.hasNode(nA) << ", " << g.hasNode(nB) << ", " << g.hasNode(nC);
    endTest();

    cout << "Insert node C\n";
    g.insertNode(nC);

    cout << "Create arc (A, B)=2\n";
    g.insertArc(nA, nB, 2);
    cout << "Are there arcs (A, B), (B, A)?";
    startTest("1, 0");
    cout << g.hasArc(nA, nB) << ", " << g.hasArc(nB, nA);
    endTest();

    cout << "Get (A, B) weight";
    startTest("2");
    cout << g.getWeight(nA, nB);
    endTest();

    cout << "Create arcs (A,C)=1, (B,A)=3\n";
    g.insertArc(nA, nC, 1);
    g.insertArc(nB, nA, 3);

    List<Node> * l;
    List<Node>::cell c;
    cout << "Print A's adjacents:";
    startTest("B, C,");
    l = g.getAdjacents(nA);
    c = l->getFirst();
    while (!l->eol(c))
    {
        cout << g.getValue(l->read(c)) << ", ";
        c = l->getNext(c);
    }
    endTest();

    cout << "Print B's adjacents:";
    startTest("A, ");
    l = g.getAdjacents(nB);
    c = l->getFirst();
    while (!l->eol(c))
    {
        cout << g.getValue(l->read(c)) << ", ";
        c = l->getNext(c);
    }
    endTest();

    cout << "Print C's adjacents:";
    startTest("");
    l = g.getAdjacents(nC);
    c = l->getFirst();
    while (!l->eol(c))
    {
        cout << g.getValue(l->read(c)) << ", ";
        c = l->getNext(c);
    }
    endTest();

    cout << "Remove arc (B,A)\n";
    g.removeArc(nB, nA);
    cout << "Is there arc (B,A)?";
    startTest("0");
    cout << g.hasArc(nB, nA);
    endTest();

    cout << "Remove node C\n";
    g.removeNode(nC);
    cout << "Are there arc (A,C) and node C?";
    startTest("0, 0");
    cout << g.hasArc(nA, nC) << ", " << g.hasNode(nC);
    endTest();

    cout << "Remove all nodes\n";
    g.removeNode(nA);
    g.removeNode(nB);
    cout << "Is graph empty?";
    startTest("1");
    cout << g.isEmpty();
    endTest();

    cout << "End";
}
