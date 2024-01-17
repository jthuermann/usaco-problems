// USACO 2019 US Open Contest, Bronze
// Problem 2. Milk Factory
// http://www.usaco.org/index.php?page=viewproblem2&cpid=940

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

set<int> bfs(vector<vector<int>>& graph, int start) {
    set<int> visited;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int v = q.back();
        q.pop();
        if (!visited.count(v)) {
            visited.insert(v);
            for (int neighbour: graph[v])
                q.push(neighbour);
        }
    }
    return visited;
}

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<int>> graph(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
    }
    set<int> intersect;
    for (int i = 0; i < N; i++)
        intersect.insert(i);
    for (int i = 0; i < N; i++) {
        set<int> a(intersect.begin(), intersect.end());
        set<int> b = bfs(graph, i);
        intersect.clear();
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(intersect, intersect.begin()));
    }
    if (intersect.size() > 0) {
        cout << *min_element(intersect.begin(), intersect.end()) + 1 << endl;
    } else {
        cout << -1 << endl;
    }
}
