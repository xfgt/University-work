// Graph.cpp

// Работа на Теодор Мангъров, F113621
// Компилирано с MSVC
// Ползвана версия C++ 20

#include "Graph.h"

bool Graph::addVertex(char vertex) {
	m_graph[vertex] = {};
	return true;
}

bool Graph::addEdge(char v1, char v2) {
	m_graph[v1].push_back(v2);
	m_graph[v2].push_back(v1);
	return true;
}


bool Graph::printGraph() {
	for (const auto& element : m_graph) {
		std::cout << element.first << " : ";


		for (const auto& curEdge : element.second) {
			std::cout << curEdge << ' ';
		}
		std::cout << '\n';


	}
	return true;
}

Graph Graph::squareGraph() {
	Graph squareGraphObj;
	for (const auto& [u, vertexNeighboursSet] : m_graph) {
		std::unordered_set<char> distance2;

		for (char v : vertexNeighboursSet) {
			squareGraphObj.m_graph[u].push_back(v);



			for (char w : m_graph.at(v)) { // all vertices with distance 2 from u


				if (w != u &&
					std::find(m_graph.at(u).begin(), m_graph.at(u).end(), w) == m_graph.at(u).end())

				{
					distance2.insert(w);
				}
			}
		}

		for (char element : distance2) {
			squareGraphObj.m_graph[u].push_back(element);
		}
	}
	return squareGraphObj;
}
