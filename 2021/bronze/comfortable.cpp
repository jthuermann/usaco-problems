// USACO 2021 February Contest
// Problem 2. Comfortable Cows
// http://usaco.org/index.php?page=viewproblem2&cpid=1108

#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, map<int, int>> cows;
    set<pair<int, int>> exists;
    int amount = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        exists.insert(make_pair(x, y));
        int before = (cows[x-1][y] == 3) + (cows[x+1][y] == 3) + (cows[x][y+1] == 3) + (cows[x][y-1] == 3);
        if (exists.count({x-1, y})) {
            cows[x-1][y]++;
            cows[x][y]++;
        }
        if (exists.count({x+1, y})) {
            cows[x+1][y]++;
            cows[x][y]++;
        }
        if (exists.count({x, y+1})) {
            cows[x][y+1]++;
            cows[x][y]++;
        }
        if (exists.count({x, y-1})) {
            cows[x][y-1]++;
            cows[x][y]++;
        }
        int after = (cows[x-1][y] == 3) + (cows[x+1][y] == 3) + (cows[x][y+1] == 3) + (cows[x][y-1] == 3);
        amount += after - before + (cows[x][y] == 3);
        cout << amount << endl;
    }
}
