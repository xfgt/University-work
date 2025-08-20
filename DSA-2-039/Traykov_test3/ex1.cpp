
// Ex. 1
#include <iostream>
#include <vector>
#include <algorithm>


const int _maxint_ = 100003;

int paretns[_maxint_], ds[_maxint_];


int find(int x) {
    if (paretns[x] != x)
        paretns[x] = find(paretns[x]);
    return paretns[x];
}


bool AUB(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (ds[x] < ds[y]) std::swap(x, y);
    paretns[y] = x;


    ds[x] += ds[y];
    return true;
}

int main() {
    
    int trials;
    std::cin >> trials;

    while (trials--) {
        int N, M, K;
        std::cin >> N >> M >> K;

        
        for (int i = 1; i <= N; i++) {
            paretns[i] = i;
            ds[i] = 1;
        }

        for (int i = 0; i < M; i++) {
            int u, v;
            std::cin >> u >> v;
            AUB(u, v);
        }

        std::vector<int> koreni;
        for (int i = 1; i <= N; i++) {
            if (find(i) == i)
                koreni.push_back(i);
        }

        int regions = koreni.size();
        int min_regions = std::max(1, regions - K);
        int max_regions = regions;

        std::cout << min_regions << " " << max_regions << "\n";
    }

    return 0;
}
