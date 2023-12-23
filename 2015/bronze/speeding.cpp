// USACO 2015 December Contest, Bronze
// Problem 2. Speeding Ticket
// http://www.usaco.org/index.php?page=viewproblem2&cpid=568

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> n, m;
    for (int i = 0; i < N; i++) {
        int length, speed_limit;
        cin >> length >> speed_limit;
        if (i == 0)
            n.push_back(make_pair(length, speed_limit));
        else
            n.push_back(make_pair(n[n.size() - 1].first + length, speed_limit));
    }
    for (int i = 0; i < M; i++) {
        int length, speed;
        cin >> length >> speed;
        if (i == 0)
            m.push_back(make_pair(length, speed));
        else
            m.push_back(make_pair(m[m.size() - 1].first + length, speed));
    }
    int max_speeding = 0;
    int position = 1;
    int index_n = 0;
    int index_m = 0;
    while (position <= 100) {
        if (m[index_m].second - n[index_n].second > max_speeding)
            max_speeding = m[index_m].second - n[index_n].second;
        position = min(n[index_n].first, m[index_m].first) + 1;
        if (n[index_n].first == position - 1)
            index_n++;
        if (m[index_m].first == position - 1)
            index_m++;
    }
    cout << max_speeding;
}
