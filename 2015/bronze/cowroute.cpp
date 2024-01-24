// USACO 2015 January Contest, Bronze
// Problem 1. Cow Routing
// https://usaco.org/index.php?page=viewproblem2&cpid=507
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    int A, B, N;
    cin >> A >> B >> N;
    int min_cost = -1;
    for (int i = 0; i < N; i++) {
        int cost, cities;
        cin >> cost >> cities;
        vector<int> route(cities);
        for (int j = 0; j < cities; j++)
            cin >> route[j];
        int ind_a = find(route.begin(), route.end(), A) - route.begin();
        int ind_b = find(route.begin(), route.end(), B) - route.begin();
        if (ind_a == cities || ind_b == cities || ind_b < ind_a)
            continue;
        if (min_cost == -1 || cost < min_cost)
            min_cost = cost;
    }
    cout << min_cost << endl;
}
