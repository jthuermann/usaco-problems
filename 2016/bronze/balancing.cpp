// USACO 2016 February Contest, Bronze
// Problem 3. Load Balancing
// http://www.usaco.org/index.php?page=viewproblem2&cpid=617

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_m(vector<pair<int, int>>& cows, int a, int b) {
    vector<int> count(4, 0);
    for (pair<int, int> cow: cows) {
        if (cow.first < a) {
            if (cow.second < b)
                count[0]++;
            else
                count[1]++;
        } else {
            if (cow.second < b)
                count[2]++;
            else
                count[3]++;
        }
    }
    return *max_element(count.begin(), count.end());
}

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int N, B;
    cin >> N >> B;
    vector<pair<int, int>> cows(N);
    vector<int> x, y;
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
        x.push_back(cows[i].first);
        y.push_back(cows[i].second);
    }
    sort(cows.begin(), cows.end());
    int min_m = 999999;
    for (int a: x) {
        for (int b: y) {
            min_m = min(min_m, count_m(cows, a, b));
        }
    }
    cout << min_m;
}
