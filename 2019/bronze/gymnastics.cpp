// USACO 2019 December Contest, Bronze
// Problem 1. Cow Gymnastics
// http://www.usaco.org/index.php?page=viewproblem2&cpid=963

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int K, N;
    cin >> K >> N;
    vector<vector<int>> practices(K);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            int cow;
            cin >> cow;
            practices[i].push_back(cow - 1);
        }
    }
    int amount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int better = -1;
            bool is_consistent = true;
            for (vector<int> practice: practices) {
                for (int cow: practice) {
                    if (cow == i || cow == j) {
                        if (better == -1) {
                            better = cow;
                            break;
                            cout << "better cow is" << cow;
                        } else if (better != cow) {
                            is_consistent = false;
                            break;
                        } else {
                            break;
                        }
                    }
                }
                if (!is_consistent)
                    break;
            }
            if (is_consistent)
                amount++;
        }
    }
    cout << amount;
}
