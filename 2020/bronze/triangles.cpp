// USACO 2020 February Contest, Bronze
// Problem 1. Triangles
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1011

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i];
    int max_area = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++) {
                if (x[i] == x[j] && (y[k] == y[i] || y[k] == y[j])) {
                    max_area = max(max_area, abs(y[i] - y[j]) * abs(x[i] - x[k]));
                }
                if (x[j] == x[k] && (y[i] == y[j] || y[i] == y[k])) {
                    max_area = max(max_area, abs(y[j] - y[k]) * abs(x[j] - x[i]));
                }
                if (x[k] == x[i] && (y[j] == y[i] || y[j] == y[k])) {
                    max_area = max(max_area, abs(y[k] - y[i]) * abs(x[k] - x[j]));
                }
            }
    cout << max_area;
}
