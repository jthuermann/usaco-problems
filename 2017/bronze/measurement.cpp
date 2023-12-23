// USACO 2017 December Contest, Bronze
// Problem 3. Milk Measurement
// https://usaco.org/index.php?page=viewproblem2&cpid=761

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool comp(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<0>(a) < get<0>(b);
}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int N;
    cin >> N;
    vector<tuple<int, int, int>> log;
    for (int i = 0; i < N; i++) {
        int day, change;
        string name;
        cin >> day >> name >> change;
        log.push_back(make_tuple(day, name == "Bessie" ? 0 : (name == "Elsie" ? 1 : 2), change));
    }
    sort(log.begin(), log.end(), comp);
    vector<int> amounts {7,7,7};
    vector<bool> highest {true,true,true};
    int changes = 0;
    for (tuple<int, int, int> entry: log) {
        amounts[get<1>(entry)] += get<2>(entry);
        int m = max(amounts[0], max(amounts[1], amounts[2]));
        bool changed = false;
        for (int i = 0; i < 3; i++) {
            if (highest[i] != (amounts[i] == m)) {
                changed = true;
                highest[i] = amounts[i] == m;
            }
        }
        if (changed)
            changes++;
    }
    cout << changes;
}
