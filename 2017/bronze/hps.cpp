// USACO 2017 January Contest, Bronze
// Problem 2. Hoof, Paper, Scissors
// http://www.usaco.org/index.php?page=viewproblem2&cpid=688

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> games(3);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b)
            continue;
        if (a != 1 && b != 1 && a > b)
            games[0].first++;
        if (a != 1 && b != 1 && a < b)
            games[0].second++;
        if (a != 2 && b != 2 && a > b)
            games[1].first++;
        if (a != 2 && b != 2 && a < b)
            games[1].second++;
        if (a != 3 && b != 3 && a > b)
            games[2].first++;
        if (a != 3 && b != 3 && a < b)
            games[2].second++;
    }
    cout << max(games[0].first + games[1].second + games[2].first, games[0].second + games[1].first + games[2].second) << endl;
}
