// USACO 2022 January Contest, Bronze
// Problem 3. Drought
// http://usaco.org/index.php?page=viewproblem2&cpid=1181

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        long long N;
        cin >> N;
        vector<long long> hunger;
        long long sum = 0;
        for (int j = 0; j < N; j++) {
            int h;
            cin >> h;
            hunger.push_back(h);
            sum += h;
        }
        int m = *min_element(hunger.begin(), hunger.end());
        bool fail = false;
        for (int j = 1; j < N; j++) {
            if (hunger[j] > hunger[j-1]) {
                if (j == N-1 || hunger[j] < 0) {
                    fail = true;
                    break;
                }
                int offset = hunger[j] - hunger[j-1];
                hunger[j] -= offset;
                hunger[j+1] -= offset;
            } else if (hunger[j] < hunger[j-1]) {
                if (j % 2 == 1 || hunger[j] < 0) {
                    fail = true;
                    break;
                }
                int offset = hunger[j-1] - hunger[j];
                for (int k = 0; k < j; k++)
                    hunger[k] -= offset;
            }
        }
        if (fail) {
            cout << -1 << endl;
        } else {
            cout << sum - hunger[0] * N << endl;
        }
    }
}