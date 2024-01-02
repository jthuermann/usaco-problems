// USACO 2016 February Contest, Bronze
// Problem 1. Milk Pails
// http://www.usaco.org/index.php?page=viewproblem2&cpid=615

#include <iostream>

using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int X, Y, M;
    cin >> X >> Y >> M;
    int max_volume = 0;
    for (int i = 0; i <= M/X; i++) {
        max_volume = max(max_volume, i*X + ((int) ((M - i*X) / Y))*Y);
    }
    cout << max_volume;
}
