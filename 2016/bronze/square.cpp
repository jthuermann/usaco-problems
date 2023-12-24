// USACO 2016 December Contest, Bronze
// Problem 1. Square Pasture
// http://www.usaco.org/index.php?page=viewproblem2&cpid=663

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int x_range = max(max(max(x1, x2), x3), x4) - min(min(min(x1, x2), x3), x4);
    int y_range = max(max(max(y1, y2), y3), y4) - min(min(min(y1, y2), y3), y4);
    cout << pow(max(x_range, y_range), 2);
}
