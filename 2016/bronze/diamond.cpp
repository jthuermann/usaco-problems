// USACO 2016 US Open Contest, Bronze
// Problem 1. Diamond Collector
// http://www.usaco.org/index.php?page=viewproblem2&cpid=639

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    vector<int> sizes(N);
    for (int i = 0; i < N; i++)
        cin >> sizes[i];
    sort(sizes.begin(), sizes.end());
    int max_amount = 0;
    for (int start_index = 0; start_index < N; start_index++) {
        int amount = 0;
        for (int i = start_index; i < N; i++) {
            if (sizes[i] <= sizes[start_index] + K)
                amount++;
            else
                break;
        }
        max_amount = max(max_amount, amount);
    }
    cout << max_amount;
}
