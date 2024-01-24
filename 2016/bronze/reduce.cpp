// USACO 2016 US Open Contest, Bronze
// Problem 3. Field Reduction
// http://www.usaco.org/index.php?page=viewproblem2&cpid=641

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> x_sorted, y_sorted;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x_sorted.push_back(make_pair(x, y));
        y_sorted.push_back(make_pair(x, y));
    }
    sort(x_sorted.begin(), x_sorted.end());
    sort(y_sorted.begin(), y_sorted.end(), cmp);
    set<pair<int, int>> ends {x_sorted[0], x_sorted[N-1], y_sorted[0], y_sorted[N-1]};
    int min_area = INT32_MAX;
    for (pair<int, int> cow: ends) {
        int x_from = (cow == x_sorted[0]) ? x_sorted[1].first : x_sorted[0].first;
        int x_to = (cow == x_sorted[N-1]) ? x_sorted[N-2].first : x_sorted[N-1].first;
        int y_from = (cow == y_sorted[0]) ? y_sorted[1].second : y_sorted[0].second;
        int y_to = (cow == y_sorted[N-1]) ? y_sorted[N-2].second : y_sorted[N-1].second;
        min_area = min(min_area, (x_to - x_from) * (y_to - y_from));
    }
    cout << min_area << endl;
}
