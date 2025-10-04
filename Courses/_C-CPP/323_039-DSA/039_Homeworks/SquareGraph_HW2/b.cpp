#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>


//nasochen
class Graph {
public:
    // Add a directed edge from u to v


    void addEdge(const std::string& u, const std::string& v) {
        adjList[u].push_back(v);


        // Ensure v is present in the map even if it has no outgoing edges
        if (adjList.find(v) == adjList.end()) {
            adjList[v] = std::vector<std::string>();
        }
    }

    // Compute the square of the graph
    Graph computeSquareGraph() const {
        Graph squareGraph;

        for (std::unordered_map<std::string, std::vector<std::string>>::const_iterator it = adjList.begin(); it != adjList.end(); ++it) {
            const std::string& u = it->first;
            const std::vector<std::string>& neighbors = it->second;

            std::unordered_set<std::string> reachable;

            // Step 1: Add direct neighbors
            for (std::vector<std::string>::const_iterator vit = neighbors.begin(); vit != neighbors.end(); ++vit) {
                const std::string& v = *vit;
                reachable.insert(v);

                // Step 2: Add neighbors of neighbors
                std::unordered_map<std::string, std::vector<std::string>>::const_iterator wit = adjList.find(v);
                if (wit != adjList.end()) {
                    const std::vector<std::string>& wNeighbors = wit->second;
                    for (std::vector<std::string>::const_iterator w_it = wNeighbors.begin(); w_it != wNeighbors.end(); ++w_it) {
                        reachable.insert(*w_it);
                    }
                }
            }

            // Add edges to squareGraph
            for (std::unordered_set<std::string>::const_iterator rit = reachable.begin(); rit != reachable.end(); ++rit) {
                squareGraph.addEdge(u, *rit);
            }
        }

        return squareGraph;
    }

    // Print the adjacency list
    void print() const {
        for (auto it = adjList.begin(); it != adjList.end(); ++it) {
            std::cout << it->first << ": ";
            for (auto vit = it->second.begin(); vit != it->second.end(); ++vit) {
                std::cout << *vit << " ";
            }
            std::cout << "\n";
        }
    }

private:
    std::unordered_map<std::string, std::vector<std::string>> adjList;
};



int main() {
    Graph G;
    G.addEdge("A", "B");
    G.addEdge("A", "C");
    G.addEdge("B", "C");
    G.addEdge("B", "D");
    G.addEdge("C", "D");

    std::cout << "Original Graph:\n";
    G.print();

    Graph square = G.computeSquareGraph();
    std::cout << "\nSquare Graph:\n";
    square.print();

    return 0;
}
