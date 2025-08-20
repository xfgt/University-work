#include <iostream>
using namespace std;

long long maxCoveredArea(int n, int b) {
    long long totalArea = (b * b) / 2;
    long long maxCover = totalArea * n / (n + 1);
    return maxCover;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, b;
        cin >> n >> b;
        cout << maxCoveredArea(n, b) << endl;
    }
    return 0;
}
