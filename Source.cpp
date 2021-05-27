#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
	Graph g;
	g.addVertex(0);
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);
	g.addVertex(6);

	g.addEdge(0, 1);
	g.addEdge(0, 5);
	g.addEdge(5, 1);
	g.addEdge(2, 1);
	g.addEdge(3, 2);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(3, 6);

	g.findPairs();
}