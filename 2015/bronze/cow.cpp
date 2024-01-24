// USACO 2015 February Contest, Bronze
// Problem 2. COW
// http://www.usaco.org/index.php?page=viewproblem2&cpid=527

#include <iostream>

using namespace std;

int main() {
    freopen("cow.in", "r", stdin);
    freopen("cow.out", "w", stdout);
    int N;
    cin >> N;
    long long amount = 0;
    int cs = 0, os = 0;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'C') {
            cs++;
        } else if (c == 'O') {
            os += cs;
        } else if (c == 'W') {
            amount += os;
        }
    }
    cout << amount << endl;
}
