#include "Graph.h"

using namespace std;

int main() {

    Graph g(6, 8);

    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, 7);

    g.printM();
    int numEdges = 0;
    LinkedList lst = g.BFS(0, numEdges);
    lst.print();


    return 0;
}