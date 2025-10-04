
// Работа на Теодор Мангъров, F113621
// Компилирано с MSVC
// Ползвана версия C++ 20


#include <iostream>
#include "Graph.h"


int main() {

	Graph G;
	G.addVertex('A');
	G.addVertex('B');
	G.addVertex('C');
	G.addVertex('D');

	G.addEdge('A', 'B');
	G.addEdge('B', 'C');
	G.addEdge('C', 'D');
	
	G.printGraph();

	std::cout << "\nG^2\n";
	Graph g2 = G.squareGraph();
	g2.printGraph();


	return 0;
}