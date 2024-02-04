// USACO 2017 January Contest, Silver
// Problem 2. Hoof, Paper, Scissors
// http://www.usaco.org/index.php?page=viewproblem2&cpid=691

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int N;
    cin >> N;
    vector<tuple<int, int, int>> sums {{0, 0, 0}};
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        tuple<int, int, int> prev = sums[sums.size() - 1];
        sums.push_back(make_tuple(get<0>(prev) + (c == 'H'), get<1>(prev) + (c == 'P'), get<2>(prev) + (c == 'S')));
    }
    int max_wins = 0;
    tuple<int, int, int> total = sums[sums.size() - 1];
    for (int i = 0; i < N; i++) {
        int h1 = get<0>(sums[i]);
        int p1 = get<1>(sums[i]);
        int s1 = get<2>(sums[i]);
        int h2 = get<0>(total) - h1;
        int p2 = get<1>(total) - p1;
        int s2 = get<2>(total) - s1;
        max_wins = max(max_wins, max(max(h1, p1), s1) + max(max(h2, p2), s2));
    }
    cout << max_wins << endl;
}