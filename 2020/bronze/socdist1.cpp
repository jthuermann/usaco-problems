// USACO 2020 US Open Contest, Bronze
// Problem 1. Social Distancing I
// http://usaco.org/index.php?page=viewproblem2&cpid=1035

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int N;
    cin >> N;
    int last = -1, front = -1, back;
    vector<int> distances;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == '0')
            continue;
        if (last != -1)
            distances.push_back(i - last);
        else
            front = i;
        last = i;
    }
    back = (last == -1) ? N : N - last - 1;
    sort(distances.begin(), distances.end());
    if (front == -1) {
        cout << back - 1 << endl;
    } else if (distances.empty()) {
        cout << max(min(back, front), max(back, front) / 2);
    } else {
        int m1 = distances[distances.size() - 1];
        if (distances.size() == 1) {
            cout << min(max(max(min(back, front), max(back, front) / 2), m1 / 3), distances[0]) << endl;
        } else {
            int m2 = distances[distances.size() - 2];
            cout << min(max(max(max(max(min(back, front), max(back, front) / 2), m1 / 3), m2 / 2), min(max(back, front), m1 / 2)), distances[0]) << endl;
        }
    }
}
