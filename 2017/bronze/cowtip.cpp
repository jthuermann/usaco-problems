// USACO 2017 January Contest, Bronze
// Problem 3. Cow Tipping
// http://www.usaco.org/index.php?page=viewproblem2&cpid=689

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<bool>> cows(N);
    int max_x = 0, max_y = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            char cow;
            cin >> cow;
            cows[x].push_back(cow == '1');
            if (cows[x][y]) {
                max_x = max(max_x, x);
                max_y = max(max_y, y);
            }
        }
    }
    int flips = 0;
    for (int x = max_x; x >= 0; x--)
        for (int y = max_y; y >= 0; y--)
            if (cows[x][y]) {
                flips++;
                for (int X = x; X >= 0; X--) {
                    for (int Y = y; Y >= 0; Y--) {
                        cows[X][Y] = !cows[X][Y];
                    }
                }
            }
    cout << flips << endl;
}
