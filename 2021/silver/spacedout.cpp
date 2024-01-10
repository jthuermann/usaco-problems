// USACO 2021 January Contest, Silver
// Problem 3. Spaced Out
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1088

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> beauty(N, vector<int>(N));
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> beauty[x][y];
    int horizontal = 0, vertical = 0;
    for (int y = 0; y < N; y++) {
        int a = 0, b = 0;
        for (int x = 0; x < N; x++) {
            if (x % 2 == 0)
                a += beauty[x][y];
            else
                b += beauty[x][y];
        }
        horizontal += max(a, b);
    }
    for (int x = 0; x < N; x++) {
        int a = 0, b = 0;
        for (int y = 0; y < N; y++) {
            if (y % 2 == 0)
                a += beauty[x][y];
            else
                b += beauty[x][y];
        }
        vertical += max(a, b);
    }
    cout << max(horizontal, vertical) << endl;
}
