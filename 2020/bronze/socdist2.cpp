// USACO 2020 US Open Contest, Bronze
// Problem 2. Social Distancing II
// http://usaco.org/index.php?page=viewproblem2&cpid=1035

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, bool>> cows;
    for (int i = 0; i < N; i++) {
        int position, infected;
        cin >> position >> infected;
        cows.push_back(make_pair(position, infected));
    }
    sort(cows.begin(), cows.end());
    int max_R = 999999999;
    for (int i = 1; i < N-1; i++) {
        if (cows[i].second && !cows[i-1].second)
            max_R = min(max_R, cows[i].first - cows[i-1].first - 1);
        if (cows[i].second && !cows[i+1].second)
            max_R = min(max_R, cows[i+1].first - cows[i].first - 1);
    }
    int amount = 0;
    for (int i = 0; i < N; i++) {
        if (!cows[i].second)
            continue;
        if (i == 0 || cows[i].first > cows[i-1].first + max_R)
            amount++;
    }
    cout << amount << endl;
}
