// USACO 2020 US Open Contest, Bronze
// Problem 3. Cowntact Tracing
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1037

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    int N, T;
    cin >> N >> T;
    vector<pair<int, pair<int, int>>> greetings;
    vector<bool> infected;
    for (int i = 0; i < N; i++) {
        char cow;
        cin >> cow;
        infected.push_back(cow == '1');
    }
    for (int i = 0; i < T; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        greetings.push_back(make_pair(t, make_pair(x-1, y-1)));
    }
    sort(greetings.begin(), greetings.end());
    int patient_zero = 0, min_K = 999999, max_K = 0;
    for (int i = 0; i < N; i++) {
        bool solution = false;
        if (!infected[i])
            continue;
        for (int K = 0; K <= T; K++) {
            vector<int> infecting(N, -1);
            infecting[i] = K;
            for (auto greeting: greetings) {
                int x = greeting.second.first, y = greeting.second.second;
                if (infecting[x] > 0) {
                    infecting[x]--;
                    if (infecting[y] == -1)
                        infecting[y] = K+1;
                }
                if (infecting[y] > 0) {
                    infecting[y]--;
                    if (infecting[x] == -1)
                        infecting[x] = K;
                }
            }
            bool correct = true;
            for (int j = 0; j < N; j++)
                if (infected[j] != (infecting[j] != -1)) {
                    correct = false;
                    break;
                }
            if (correct) {
                min_K = min(min_K, K);
                max_K = max(max_K, K);
                solution = true;
            }
        }
        if (solution) {
            patient_zero++;
        }
    }
    cout << patient_zero << " " << min_K << " " << (max_K == T ? "Infinity" : to_string(max_K));
}
