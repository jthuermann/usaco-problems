// USACO 2021 US Open, Bronze
// Problem 3. Acowdemia III
// http://usaco.org/index.php?page=viewproblem2&cpid=1133

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    set<pair<int, int>> cows;
    set<pair<int, int>> grass;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            char c;
            cin >> c;
            if (c == 'C')
                cows.insert(make_pair(x, y));
            else if (c == 'G')
                grass.insert(make_pair(x, y));
        }
    }
    int amount = 0;
    set<pair<pair<int, int>, pair<int, int>>> used;
    for (pair<int, int> g: grass) {
        vector<pair<int, int>> adjacent;
        if (cows.count(make_pair(g.first, g.second-1)))
            adjacent.push_back(make_pair(g.first, g.second-1));
        if (cows.count(make_pair(g.first-1, g.second)))
            adjacent.push_back(make_pair(g.first-1, g.second));
        if (cows.count(make_pair(g.first+1, g.second)))
            adjacent.push_back(make_pair(g.first+1, g.second));
        if (cows.count(make_pair(g.first, g.second+1)))
            adjacent.push_back(make_pair(g.first, g.second+1));
        if (adjacent.size() < 2) {
            continue;
        } else if (adjacent.size() == 2 && !used.count(make_pair(adjacent[0], adjacent[1]))) {
            amount++;
            used.insert(make_pair(adjacent[0], adjacent[1]));
        } else if (adjacent.size() > 2) {
            amount++;
        }
    }
    cout << amount << endl;
}
