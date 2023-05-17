#include "headers.h"

int main() {
Graph g(4);
g.addEdge(0, 1);
g.addEdge(0, 2);
g.addEdge(1, 2);
g.printGraph();

Copy
g.complement(); 
cout << "Complement: " << endl; 
g.printGraph(); 
return 0;
}