// USACO 2018 US Open Contest, Bronze
// Problem 1. Team Tic Tac Toe
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    vector<char> field;
    for (int i = 0; i < 9; i++) {
        char cow;
        cin >> cow;
        field.push_back(cow);
    }
    const vector<vector<int>> wins {{0,3,6}, {1,4,7}, {2,5,8}, {0,1,2}, {3,4,5}, {6,7,8}, {0,4,8}, {2,4,6}};
    set<int> solo;
    set<set<char>> team;
    for (const vector<int>& win: wins) {
        set<char> cows;
        for (int position: win) {
            cows.insert(field[position]);
        }
        if (cows.size() == 1)
            solo.insert(*cows.begin());
        if (cows.size() == 2)
            team.insert(cows);
    }
    cout << solo.size() << endl;
    cout << team.size() << endl;
}