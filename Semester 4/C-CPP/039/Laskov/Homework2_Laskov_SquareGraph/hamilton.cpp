#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>


struct Graph {
    using GraphType = std::unordered_map<char, std::vector<char>>;
    GraphType m_graph;

    bool addVertex(char vertex) {
        m_graph[vertex]; // implicitly creates empty list if not exists
        return true;
    }

    bool addEdge(char from, char to) {
        m_graph[from].push_back(to); // only one direction for directed graph
        return true;
    }

    bool printGraph() {
        for (const auto& [vertex, neighbors] : m_graph) {
            std::cout << vertex << " -> ";
            for (char neighbor : neighbors) {
                std::cout << neighbor << ' ';
            }
            std::cout << '\n';
        }
        return true;
    }

    Graph squareGraph() {
        Graph squareGraphObj;

        for (const auto& [u, neighbors] : m_graph) {
            std::unordered_set<char> distance2;

            for (char v : neighbors) {
                squareGraphObj.m_graph[u].push_back(v); // original edge

                for (char w : m_graph[v]) { // v → w
                    if (w != u && std::find(m_graph[u].begin(), m_graph[u].end(), w) == m_graph[u].end()) {
                        distance2.insert(w); // add second-level neighbor if not already connected
                    }
                }
            }

            for (char w : distance2) {
                squareGraphObj.m_graph[u].push_back(w);
            }
        }

        return squareGraphObj;
    }

    bool hasHamiltonianCycle() {
        if (m_graph.empty()) return false;

        for (const auto& [start, x] : m_graph) {
            std::unordered_set<char> visited;
            std::vector<char> path;

            visited.insert(start);
            path.push_back(start);

            if (isHamiltonianCycleUtil(start, visited, path, start, m_graph.size()))
                return true;
        }

        return false;
    }

private:
    bool isHamiltonianCycleUtil(char current, std::unordered_set<char>& visited,
        std::vector<char>& path, char start, int totalVertices) {
        if (path.size() == totalVertices) {
            for (char neighbor : m_graph[current]) {
                if (neighbor == start) {
                    path.push_back(start); // optionally store full cycle
                    return true;
                }
            }
            return false;
        }

        for (char neighbor : m_graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                path.push_back(neighbor);

                if (isHamiltonianCycleUtil(neighbor, visited, path, start, totalVertices))
                    return true;

                visited.erase(neighbor);
                path.pop_back();
            }
        }

        return false;
    }
};

int main() {
    Graph G;

    G.addVertex('A');
    G.addVertex('B');
    G.addVertex('C');
    G.addVertex('D');

    G.addEdge('A', 'B');
    G.addEdge('B', 'C');
    G.addEdge('C', 'D');



    //G.addVertex('A');
    //G.addVertex('B');
    //G.addVertex('C');
    //G.addVertex('D');

    //G.addEdge('A', 'B');
    //G.addEdge('B', 'C');
    //G.addEdge('C', 'D');
    //G.addEdge('D', 'A'); // makes it a cycle


    

    std::cout << "Original Graph (Directed):\n";
    G.printGraph();

    std::cout << "\nSquare Graph G^2:\n";
    Graph G2 = G.squareGraph();
    G2.printGraph();

    std::cout << "\nChecking for Hamiltonian cycle in G^2:\n";
    if (G2.hasHamiltonianCycle()) {
        std::cout << "G^2 has a Hamiltonian cycle.\n";
    }
    else {
        std::cout << "G^2 does NOT have a Hamiltonian cycle.\n";
    }

    return 0;
}
