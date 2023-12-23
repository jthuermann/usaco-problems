// USACO 2015 December Contest, Bronze
// Problem 1. Fence Painting
// http://www.usaco.org/index.php?page=viewproblem2&cpid=567

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << b - a + d - c - max(min(b, d) - max(a, c), 0);
}
