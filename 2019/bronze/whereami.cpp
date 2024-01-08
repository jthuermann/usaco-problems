// USACO 2019 December Contest, Bronze
// Problem 2. Where Am I?
// http://www.usaco.org/index.php?page=viewproblem2&cpid=964

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> colors;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        colors.push_back(c);
    }
    for (int K = 1; K < N; K++) {
        bool pass = true;
        set<vector<int>> present;
        for (int i = 0; i < N - K + 1; i++) {
            vector<int> current;
            for (int j = i; j < i + K; j++)
                current.push_back(colors[j]);
            if (present.count(current)) {
                pass = false;
                break;
            }
            present.insert(current);
        }
        if (pass) {
            cout << K << endl;
            break;
        }
    }
}
