#include <iostream>
#include <vector>
#include <algorithm>

struct Ulica {
    int u, v, t;
    bool navodnena = false;
};

int find(int u, std::vector<int>& paretn) {
    if (u != paretn[u])
        paretn[u] = find(paretn[u], paretn);
    return paretn[u];
}

bool AUB(int u, int v, std::vector<int>& parent, std::vector<int>& rank) {
    int ru = find(u, parent);
    int rv = find(v, parent);
    if (ru == rv) return false;
    if (rank[ru] < rank[rv]) {
        parent[ru] = rv;
    }
    else {
        parent[rv] = ru;
        if (rank[ru] == rank[rv]) rank[ru]++;
    }
    return true;
}


bool compareUlici(const Ulica& a, const Ulica& b) {
    return a.t < b.t;
}

int main() {

    int trials;
    std::cin >> trials;
    while (trials--) {
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<Ulica> edges(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> edges[i].u >> edges[i].v >> edges[i].t;
        }

        for (int i = 0; i < k; ++i) {
            int idx;
            std::cin >> idx;
            edges[idx].navodnena = true;
        }

        std::vector<Ulica> navodneni;
        for (auto& e : edges) {
            if (e.navodnena)
                navodneni.push_back(e);
        }

        std::sort(navodneni.begin(), navodneni.end(), compareUlici);

        std::vector<int> parent(n + 1);
        std::vector<int> rank(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;

        int total = 0;
        int comps = n;
        for (auto& ul : navodneni) {
            if (AUB(ul.u, ul.v, parent, rank)) {
                total += ul.t;
                comps--;
                if (comps == 1) break;
            }
        }

        std::cout << (comps == 1 ? -1 : total) << '\n';
    }
    return 0;
}
