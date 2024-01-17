// USACO 2019 February Contest, Bronze
// Problem 2. The Great Revegetation
// http://www.usaco.org/index.php?page=viewproblem2&cpid=916

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> pastures(N);
    vector<pair<int, int>> cows;
    vector<vector<int>> possibilities(N, {0, 1,2 ,3});
    for (int i = 0; i < M; i++) {
        int fav1, fav2;
        cin >> fav1 >> fav2;
        pastures[fav1-1].push_back(i);
        pastures[fav2-1].push_back(i);
        cows.push_back(make_pair(fav1-1, fav2-1));
    }
    for (int i = 0; i < N; i++) {
        int amount = possibilities[i].size();
        for (int j = 0; j < amount - 1; j++) {
            possibilities[i].pop_back();
        }
        for (int c: pastures[i]) {
            pair<int, int> cow = cows[c];
            int pasture = cow.first == i ? cow.second : cow.first;
            for (int j = 0; j < possibilities[pasture].size(); j++) {
                if (possibilities[pasture][j] == possibilities[i][0]) {
                    possibilities[pasture].erase(possibilities[pasture].begin() + j);
                    break;
                }
            }
        }
    }
    for (vector<int> pasture: possibilities) {
        cout << pasture[0]+1;
    }
    cout << endl;
}