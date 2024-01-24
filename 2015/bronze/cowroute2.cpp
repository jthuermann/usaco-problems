// USACO 2015 January Contest, Bronze
// Problem 2. Cow Routing II
// http://www.usaco.org/index.php?page=viewproblem2&cpid=508
 
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    int A, B, N;
    cin >> A >> B >> N;
    A--, B--;
    map<int, map<int, int>> graph;
    set<int> A_to, to_B;
    for (int i = 0; i < N; i++) {
        int weight, cities;
        cin >> weight >> cities;
        vector<int> route;
        bool is_A = false;
        for (int j = 0; j < cities; j++) {
            int city;
            cin >> city;
            city--;
            if (city == B) {
                for (int c: route) {
                    to_B.insert(c);
                    if (!graph[c].count(B) || graph[c][B] > weight)
                        graph[c][B] = weight;
                }
            }
            if (is_A) {
                A_to.insert(city);
                if (!graph[A].count(city) || graph[A][city] > weight)
                    graph[A][city] = weight;
            }
            route.push_back(city);
            if (city == A)
                is_A = true;
        }
    }
    set<int> intersect;
    set_intersection(A_to.begin(), A_to.end(), to_B.begin(), to_B.end(), inserter(intersect, intersect.begin()));
    int min_cost = -1;
    if (A_to.count(B) && to_B.count(A))
        min_cost = graph[A][B];
    for (int i: intersect) {
        int cost = graph[A][i] + graph[i][B];
        if (min_cost == -1 || min_cost > cost)
            min_cost = cost;
    }
    cout << min_cost << endl;
}
