// USACO 2021 December Contest, Bronze
// Problem 3. Walking Home
// http://usaco.org/index.php?page=viewproblem2&cpid=1157

#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool check(set<pair<int, int>>& haybales, vector<int>& turns, bool direction, int N) {
    int x = 0, y = 0;
    int next_turn = 0;
    int t = turns.size();
    while (x != N-1 || y != N-1) {
        if (haybales.count(make_pair(x, y))) {
            return false;
        } else if (next_turn < t && (direction && x == turns[next_turn]) || (!direction && y == turns[next_turn])) {
            direction = !direction;
            next_turn++;
        }
        if (direction) {
            x++;
        } else {
            y++;
        }
    }
    return true;
}

int search(set<pair<int, int>>& haybales, vector<int>& choose, int turns, int N) {
    int ret = 0;
    if (turns == 1) {
        choose.push_back(N-1);
        ret += check(haybales, choose, true, N);
        ret += check(haybales, choose, false, N);
        choose.pop_back();
        return ret;
    }
    int s = choose.size();
    for (int i = (s >= 2) ? choose[s - 2] + 1 : 1; i < N-(turns)/2; i++) {
        choose.push_back(i);
        ret += search(haybales, choose, turns - 1, N);
        choose.pop_back();
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        set<pair<int, int>> haybales;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                char c;
                cin >> c;
                if (c == 'H')
                    haybales.insert(make_pair(x, y));
            }
        }
        int amount = 0;
        for (int turns = 1; turns <= K; turns++)
            amount += search(haybales, *new vector<int>(), turns, N);
        cout << amount << endl;
    }
}
