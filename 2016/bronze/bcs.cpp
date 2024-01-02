// USACO 2016 US Open Contest, Bronze
// Problem 2. Bull in a China Shop
// https://usaco.org/index.php?page=viewproblem2&cpid=640

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

pair<int, int> corner(vector<int>& figurine, int N) {
    int min_x = 99999, min_y = 99999;
    int max_x = 0, max_y = 0;
    for (int pixel: figurine) {
        min_x = min(min_x, pixel % N);
        min_y = min(min_y, pixel / N);
        max_x = max(max_x, pixel % N);
        max_y = max(max_y, pixel / N);
    }
    int offset = -min_x - N * min_y;
    for (int& i : figurine)
        i += offset;
    return { max_y - min_y + 1, max_x - min_x + 1};
}

int main() {
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    vector<int> original;
    vector<vector<int>> pieces(K);
    vector<int> height, width;
    for (int i = 0; i < N*N; i++) {
        char c;
        cin >> c;
        if (c == '#')
            original.push_back(i);
    }
    corner(original, N);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N*N; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                pieces[i].push_back(j);
            }
        }
        int h, w;
        tie(h, w) = corner(pieces[i], N);
        height.push_back(h);
        width.push_back(w);
    }
    for (int i = 0; i < K; i++) {
        for (int j = i + 1; j < K; j++) {
            if (pieces[i].size() + pieces[j].size() != original.size())
                continue;
            for (int shift_ix = 0; shift_ix <= N - width[i]; shift_ix++) {
                for (int shift_iy = 0; shift_iy <= N - height[i]; shift_iy++) {
                    for (int shift_jx = 0; shift_jx <= N - width[j]; shift_jx++) {
                        for (int shift_jy = 0; shift_jy <= N - height[j]; shift_jy++) {
                            bool passing = true;
                            for (int o: original)
                                if (!(find(pieces[i].begin(), pieces[i].end(), o-shift_ix-shift_iy*N) != pieces[i].end() ^
                                      find(pieces[j].begin(), pieces[j].end(), o-shift_jx-shift_jy*N) != pieces[j].end())) {
                                    passing = false;
                                    break;
                                }
                            if (passing) {
                                cout << i+1 << " " << j+1 << endl;
                                exit(0);
                            }
                        }
                    }
                }
            }
        }
    }
}
