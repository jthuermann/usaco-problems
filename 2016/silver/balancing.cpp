// USACO 2016 February Contest, Bronze
// Problem 3. Load Balancing
// http://www.usaco.org/index.php?page=viewproblem2&cpid=617

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_m(vector<pair<int, int>>& cows, int a, int b, int N, int above, int below) {
    vector<int> count(4, 0);
    for (pair<int, int> cow: cows) {
        if (cow.first > a)
            break;
        if (cow.second < b)
            count[0]++;
        else
            count[1]++;
    }
    count[2] = above - count[1];
    count[3] = below - count[0];
    return *max_element(count.begin(), count.end());
}

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> cows(N);
    vector<int> x, y;
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
        x.push_back(cows[i].first);
        y.push_back(cows[i].second);
    }
    sort(cows.begin(), cows.end());
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int min_m = 999999;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            min_m = min(min_m, count_m(cows, x[a]+1, y[b]+1, N, N-b-1, b+1));
        }
    }
    cout << min_m;
}
