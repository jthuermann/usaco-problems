// USACO 2018 January Contest, Bronze
// Problem 1. Blocked Billboard II
// http://www.usaco.org/index.php?page=viewproblem2&cpid=783

#include <iostream>

using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int area = abs(x1 - x2) * abs(y1- y2) + abs(x3 - x4) * abs(y3 - y4);
    int x_overlap = max(min(x2, x4) - max(x1, x3), 0);
    int y_overlap = max(min(y2, y4) - max(y1, y3), 0);
    if (x_overlap >= abs(x2 - x1) && ((y3 <= y1 && y1 <= y4) || (y3 <= y2 && y2 <= y4))) {
        cout << abs(x2 - x1) * max(abs(y2 - y1) - y_overlap, 0);
    } else if (y_overlap >= abs(y2 - y1) && ((x3 <= x1 && x1 <= x4) || (x3 <= x2 && x2 <= x4))) {
        cout << abs(y2 - y1) * max(abs(x2 - x1) - x_overlap, 0);
    } else {
        cout << abs(x2 - x1) * abs(y2 - y1);
    }
}
