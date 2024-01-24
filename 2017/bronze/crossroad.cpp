// USACO 2017 February Contest, Bronze
// Problem 1. Why Did the Cow Cross the Road
// http://usaco.org/index.php?page=viewproblem2&cpid=548

#include <iostream>
#include <map>

using namespace std;

int main() {
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);
    int N;
    cin >> N;
    map<int, int> positions;
    int amount = 0;
    for (int i = 0; i < N; i++) {
        int cow, position;
        cin >> cow >> position;
        if (!positions.count(cow))
            positions[cow] = position;
        else
            if (positions[cow] != position) {
                amount++;
                positions[cow] = position;
            }
    }
    cout << amount << endl;
}
