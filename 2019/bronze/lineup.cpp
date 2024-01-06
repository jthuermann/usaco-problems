// USACO 2019 December Contest, Bronze
// Problem 3. Livestock Lineup
// http://www.usaco.org/index.php?page=viewproblem2&cpid=965

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    vector<string> cows {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    int N;
    cin >> N;
    vector<pair<string, string>> constraints;
    for (int i = 0; i < N; i++) {
        string X, Y;
        cin >> X >> Y >> Y >> Y >> Y >> Y;
        constraints.push_back(make_pair(X, Y));
    }
    do {
        bool fail = false;
        for (const pair<string, string>& con: constraints) {
            int index = find(cows.begin(), cows.end(), con.first) - cows.begin();
            if (cows[index - 1] != con.second && cows[index + 1] != con.second) {
                fail = true;
                break;
            }
        }
        if (!fail) {
            for (const string& cow: cows)
                cout << cow << endl;
            exit(0);
        }
    } while (next_permutation(cows.begin(), cows.end()));
}
