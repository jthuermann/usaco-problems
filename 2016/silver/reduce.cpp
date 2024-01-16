// USACO 2016 US Open Contest, Bronze
// Problem 1. Field Reduction
// www.usaco.org/index.php?page=viewproblem2&cpid=642

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
    int min_area = 2147483647;
    set<pair<int, int>> ends;
    for (int i = 0; i < 3; i++) {
        ends.insert(x_sorted[i]);
        ends.insert(x_sorted[N-1-i]);
        ends.insert(y_sorted[i]);
        ends.insert(y_sorted[N-1-i]);
    }
    vector<pair<int, int>> v(ends.begin(), ends.end());
    for (int i = 0; i < v.size() - 2; i++) {
        for (int j = i + 1; j < v.size() - 1; j++) {
            for (int k = j + 1; k < v.size(); k++) {
                int x_from, x_to, y_from, y_to;
                for (int x = 0; x < 4; x++) {
                    if (x_sorted[x] != v[i] && x_sorted[x] != v[j] && x_sorted[x] != v[k]) {
                        x_from = x_sorted[x].first;
                        break;
                    }
                }
                for (int x = N-1; x >= N-4; x--) {
                    if (x_sorted[x] != v[i] && x_sorted[x] != v[j] && x_sorted[x] != v[k]) {
                        x_to = x_sorted[x].first;
                        break;
                    }
                }
                for (int y = 0; y < 4; y++) {
                    if (y_sorted[y] != v[i] && y_sorted[y] != v[j] && y_sorted[y] != v[k]) {
                        y_from = y_sorted[y].second;
                        break;
                    }
                }
                for (int y = N-1; y >= N-4; y--) {
                    if (y_sorted[y] != v[i] && y_sorted[y] != v[j] && y_sorted[y] != v[k]) {
                        y_to = y_sorted[y].second;
                        break;
                    }
                }
                min_area = min(min_area, (x_to - x_from) * (y_to - y_from));
            }
        }
    }
    cout << min_area << endl;
}
