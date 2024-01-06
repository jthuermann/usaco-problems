// USACO 2017 February Contest, Bronze
// Problem 3. Why Did the Cow Cross the Road III
// http://www.usaco.org/index.php?page=viewproblem2&cpid=713

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> cows;
    for (int i = 0; i < N; i++) {
        int arrive, questions;
        cin >> arrive >> questions;
        cows.push_back(make_pair(arrive, questions));
    }
    sort(cows.begin(), cows.end());
    int time = cows[0].first;
    for (pair<int, int> cow: cows) {
        if (cow.first <= time)
            time += cow.second;
        else
            time = cow.first + cow.second;
    }
    cout << time << endl;
}
