// USACO 2023 February Contest, Bronze
// Problem 2. Stamp Grid
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1300

#include <iostream>
#include <vector>

using namespace std;

void rotate90(vector<vector<bool>>& stamp, int K) {
    for (int x = 0; x < K / 2; x++) {
        for (int y = x; y < K - x - 1; y++) {
            int tmp = stamp[x][y];
            stamp[x][y] = stamp[y][K - 1 - x];
            stamp[y][K - 1 - x] = stamp[K - 1 - x][K - 1 - y];
            stamp[K - 1 - x][K - 1 - y] = stamp[K - 1 - y][x];
            stamp[K - 1 - y][x] = tmp;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<vector<bool>> target(N);
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                char c;
                cin >> c;
                target[x].push_back(c == '*');
            }
        }
        int K;
        cin >> K;
        vector<vector<bool>> stamp(K);
        for (int y = 0; y < K; y++) {
            for (int x = 0; x < K; x++) {
                char c;
                cin >> c;
                stamp[x].push_back(c == '*');
            }
        }
        vector<vector<bool>> canvas(N, vector<bool>(N, false));
        for (int r = 0; r < 4; r++) {
            for (int x = 0; x < N - K + 1; x++) {
                for (int y = 0; y < N - K + 1; y++) {
                    bool possible = true;
                    for (int X = 0; X < K; X++) {
                        for (int Y = 0; Y < K; Y++) {
                            if (stamp[X][Y] && !target[x+X][y+Y])
                                possible = false;
                        }
                    }
                    if (!possible)
                        continue;
                    for (int X = 0; X < K; X++) {
                        for (int Y = 0; Y < K; Y++) {
                            if (stamp[X][Y])
                                canvas[x+X][y+Y] = true;
                        }
                    }
                }
            }
            rotate90(stamp, K);
        }
        cout << (target == canvas ? "YES" : "NO") << endl;
    }
}
