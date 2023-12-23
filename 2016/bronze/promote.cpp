// USACO 2016 January Contest, Bronze
// Problem 1. Promotion Counting
// http://www.usaco.org/index.php?page=viewproblem2&cpid=591

#include <iostream>

using namespace std;

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int b1, b2, s1, s2, g1, g2, p1, p2;
    int to_s, to_g, to_p;
    cin >> b1 >> b2 >> s1 >> s2 >> g1 >> g2 >> p1 >> p2;
    to_p = p2 - p1;
    to_g = g2 - g1 + to_p;
    to_s = s2 - s1 + to_g;
    cout << to_s << endl;
    cout << to_g << endl;
    cout << to_p << endl;
}
