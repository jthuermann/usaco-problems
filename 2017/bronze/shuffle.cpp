// USACO 2017 December Contest, Bronze
// Problem 2. The Bovine Shuffle
// http://www.usaco.org/index.php?page=viewproblem2&cpid=760

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> shuffle;
    vector<int> final;
    for (int i = 0; i < N; i++) {
        int a_i;
        cin >> a_i;
        shuffle.push_back(a_i - 1);
    }
    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        final.push_back(id);
    }
    for (int i = 0; i < N; i++) {
        cout << final[shuffle[shuffle[shuffle[i]]]] << endl;
    }
}
