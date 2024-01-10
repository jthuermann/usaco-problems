// USACO 2019 February Contest, Bronze
// Problem 1. Sleepy Cow Herding
// http://www.usaco.org/index.php?page=viewproblem2&cpid=915

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> s {a, b, c};
    sort(s.begin(), s.end());
    a = s[0], b = s[1], c = s[2];
    if (c - a == 2) {
        cout << 0 << endl << 0 << endl;
    } else if (b - a == 1) {
        cout << (c == b + 2 ? 1 : 2) << endl;
        cout << c - b - 1 << endl;
    } else if (c - b == 1) {
        cout << (a == b - 2 ? 1 : 2) << endl;
        cout << b - a - 1 << endl;
    } else if (b - a == 2) {
        cout << 1 << endl;
        cout << c - b - 1;
    } else if (c - b == 2) {
        cout << 1 << endl;
        cout << b - a - 1 << endl;
    } else {
        cout << 2 << endl;
        cout << max(c - b - 1, b - a - 1);
    }
}
