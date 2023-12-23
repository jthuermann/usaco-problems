// USACO 2018 February Contest, Bronze
// Problem 1. Teleportation
// http://www.usaco.org/index.php?page=viewproblem2&cpid=807

#include <iostream>

using namespace std;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << min(abs(a-b), min(abs(a-x) + abs(y-b), abs(a-y) + abs(x-b)));
}
