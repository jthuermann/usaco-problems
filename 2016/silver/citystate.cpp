// USACO 2016 December Contest, Silver
// Problem 2. Cities and States
// http://www.usaco.org/index.php?page=viewproblem2&cpid=667

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int N;
    cin >> N;
    set<string> states;
    map<string, map<string, int>> cities;
    for (int i = 0; i < N; i++) {
        string city, state;
        cin >> city >> state;
        city = city.substr(0, 2);
        states.insert(state);
        cities[state][city]++;
    }
    vector<string> states_v(states.begin(), states.end());
    int amount = 0;
    for (int i = 0; i < states_v.size(); i++) {
        for (pair<string, int> city: cities[states_v[i]]) {
            if (states_v[i] == city.first)
                continue;
            int a = city.second * cities[city.first][states_v[i]];
            amount += a;
        }
    }
    cout << amount / 2 << endl;
}