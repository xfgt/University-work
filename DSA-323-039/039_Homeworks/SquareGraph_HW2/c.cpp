#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using Graph = unordered_map<char, vector<char>>;

Graph squareGraph(const Graph& G) {
    Graph G2;

    for (auto& [u, neighbors] : G) {
        unordered_set<char> distance2;

        // Add all direct neighbors
        for (char v : neighbors) {
            G2[u].push_back(v);
            // Find neighbors of neighbors
            for (char w : G.at(v)) {
                if (w != u && G.at(u).end() == find(G.at(u).begin(), G.at(u).end(), w)) {
                    distance2.insert(w);
                }
            }
        }

        // Add edges to distance-2 neighbors
        for (char w : distance2) {
            G2[u].push_back(w);
        }
    }

    return G2;
}

void printGraph(const Graph& G) {
    for (auto& [node, neighbors] : G) {
        cout << node << ": ";
        for (char n : neighbors) {
            cout << n << " ";
        }
        cout << endl;
    }
}

int c() {
    Graph G = {
        {'A', {'B'}},
        {'B', {'A', 'C'}},
        {'C', {'B', 'D'}},
        {'D', {'C'}}
    };

    printGraph(G);

    Graph G2 = squareGraph(G);

    cout << "Square graph G^2:\n";
    printGraph(G2);

    return 0;
}
