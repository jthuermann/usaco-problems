// USACO 2019 January Contest, Bronze
// Problem 1. Grass Planting
// http://www.usaco.org/index.php?page=viewproblem2&cpid=894

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<int>> graph(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    int colors = 0;
    for (int i = 0; i < N; i++) {
        colors = max(colors, (int) graph[i].size() + 1);
    }
    cout << colors << endl;
}