// USACO 2017 December Contest, Bronze
// Problem 1. Blocked Billboard
// http://www.usaco.org/index.php?page=viewproblem2&cpid=759

#include <iostream>

using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    int area = abs(x1 - x2) * abs(y1- y2) + abs(x3 - x4) * abs(y3 - y4);
    int blocked1 = max(min(x2, x6) - max(x1, x5), 0) * max(min(y2, y6) - max(y1, y5), 0);
    int blocked2 = max(min(x4, x6) - max(x3, x5), 0) * max(min(y4, y6) - max(y3, y5), 0);
    cout << area - blocked1 - blocked2;
}
