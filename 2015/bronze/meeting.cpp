// USACO 2015 January Contest, Bronze
// Problem 4. Meeting Time
// http://www.usaco.org/index.php?page=viewproblem2&cpid=510

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

set<int> bfs(vector<set<pair<int, pair<int, int>>>>& graph, int N, bool first) {
    queue<int> q;
    q.push(0);
    vector<set<int>> dist(1000);
    dist[0].insert(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto p: graph[v]) {
            int neighbour = p.first;
            int distance = first ? p.second.first : p.second.second;
            bool new_dist = false;
            for (int current_dist: dist[v]) {
                if (!dist[neighbour].count(current_dist + distance)) {
                    new_dist = true;
                    dist[neighbour].insert(current_dist + distance);
                }
            }
            if (new_dist)
                q.push(neighbour);
        }
    }
    return dist[N];
}

int main() {
    freopen("meeting.in", "r", stdin);
    freopen("meeting.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<set<pair<int, pair<int, int>>>> graph(1000);
    for (int i = 0; i < M; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        graph[A-1].insert(make_pair(B-1, make_pair(C, D)));
    }
    set<int> a = bfs(graph, N-1, true);
    set<int> b = bfs(graph, N-1, false);
    vector<int> intersect;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersect));
    if (intersect.empty())
        cout << "IMPOSSIBLE" << endl;
    else
        cout << *min_element(intersect.begin(), intersect.end()) << endl;
}
