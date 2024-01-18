// USACO 2017 US Open Contest, Bronze
// Problem 3. Modern Art
// http://www.usaco.org/index.php?page=viewproblem2&cpid=737

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const int COLORS = 9;

int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<pair<int, int>, pair<int, int>>> rectangles(COLORS, make_pair(make_pair(-1, -1), make_pair(-1, -1)));
    vector<vector<int>> canvas(N);
    for (int y = 0; y < N; y++) {
        long long colors;
        cin >> colors;
        for (int x = 0; x < N; x++) {
            int color = (colors / (long long) pow(10, N-x-1)) % 10;
            canvas[y].push_back(color-1);
            if (color == 0)
                continue;
            auto rect = &rectangles[color-1];
            if (rect->first.first == -1) {
                *rect = make_pair(make_pair(x, y), make_pair(x, y));
            }
            rect->first.first = min(rect->first.first, x);
            rect->first.second = min(rect->first.second, y);
            rect->second.first = max(rect->second.first, x);
            rect->second.second = max(rect->second.second, y);
        }
    }
    set<int> impossible;
    for (int i = 0; i < COLORS; i++) {
        auto rect = rectangles[i];
        if (rect.first.first == -1) {
            impossible.insert(i);
            continue;
        }
        for (int x = rect.first.first; x <= rect.second.first; x++) {
            for (int y = rect.first.second; y <= rect.second.second; y++) {
                if (canvas[y][x] != i) {
                    impossible.insert(canvas[y][x]);
                }
            }
        }
    }
    cout << COLORS - impossible.size() << endl;
}
