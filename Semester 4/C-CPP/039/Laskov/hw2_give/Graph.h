

// Graph.h
 
// Работа на Теодор Мангъров, F113621
// Компилирано с MSVC
// Ползвана версия C++ 20

#pragma once

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>


struct Graph {
	using GraphType = std::unordered_map<char, std::vector<char>>;
	
	GraphType m_graph;

	bool addVertex(char vertex);
	bool addEdge(char v1, char v2);
	bool printGraph();

	Graph squareGraph();

};