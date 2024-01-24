// USACO 2023 January Contest, Bronze
// Problem 1. Leaderss
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1275

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int first_g = -1, last_g = -1;
    int first_h = -1, last_h = -1;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'G') {
            if (first_g == -1)
                first_g = i;
            last_g = i;
        } else if (c == 'H') {
            if (first_h == -1)
                first_h = i;
            last_h = i;
        }
    }
    int leader_g = -1;
    int leader_h = -1;
    vector<int> ranges;
    for (int i = 0; i < N; i++) {
        int range;
        cin >> range;
        range--;
        ranges.push_back(range);
        if (i == first_g && range >= last_g)
            leader_g = i;
        if (i == first_h && range >= last_h)
            leader_h = i;
    }
    int amount = 0;
    if (leader_g != -1 && leader_h != -1) {
        int first = min(leader_g, leader_h);
        int last = max(leader_g, leader_h);
        if (ranges[first] < last)
            amount++;
    }
    if (leader_g != -1) {
        for (int i = 0; i < leader_g; i++) {
            if (ranges[i] >= leader_g)
                amount++;
        }
    }
    if (leader_h != -1) {
        for (int i = 0; i < leader_h; i++) {
            if (ranges[i] >= leader_h)
                amount++;
        }
    }
    cout << amount << endl;
}
