// USACO 2017 US Open Contest, Bronze
// Problem 1. The Lost Cow
// http://www.usaco.org/index.php?page=viewproblem2&cpid=735

#include <iostream>

using namespace std;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x,y;
    cin >> x >> y;
    if (x == y) {
        cout << 0;
        exit(0);
    }
    int offset = x > y ? -2 : 1;
    while (!((x >= y && y >= x+offset) || (x <= y && y <= x+offset)))
        offset *= 4;
    cout << 3 * abs(offset) - 2 - abs(x+offset-y);
}