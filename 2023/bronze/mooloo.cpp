// USACO 2023 February Contest, Bronze
// Problem 3. Watching Mooloo
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1301

#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    long long last = -1;
    long long cost = 0;
    for (int i = 0; i < N; i++) {
        long long day;
        cin >> day;
        if (last == -1 || day - last > K) {
            cost += K + 1;
        } else {
            cost += day - last;
        }
        last = day;
    }
    cout << cost << endl;
}
