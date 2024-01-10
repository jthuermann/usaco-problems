// USACO 2019 January Contest, Bronze
// Problem 2. Sleepy Cow Sorting
// http://www.usaco.org/index.php?page=viewproblem2&cpid=892

#include <iostream>

using namespace std;

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int N;
    cin >> N;
    int max_sorted = 0;
    int last = 0;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (p > last)
            max_sorted++;
        else
            max_sorted = 1;
        last = p;
    }
    cout << N - max_sorted << endl;
}