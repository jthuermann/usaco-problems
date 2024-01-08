// USACO 2017 January Contest, Bronze
// Problem 1. Don't Be Last!
// http://www.usaco.org/index.php?page=viewproblem2&cpid=687

#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int N;
    cin >> N;
    map<string, int> milk;
    milk["Bessie"] = 0, milk["Elsie"] = 0, milk["Daisy"] = 0, milk["Gertie"] = 0, milk["Annabelle"] = 0, milk["Henrietta"] = 0;
    for (int i = 0; i < N; i++) {
        string cow; int amount;
        cin >> cow >> amount;
        milk[cow] += amount;
    }
    set<int> amounts;
    for (pair<string, int> cow: milk)
        amounts.insert(cow.second);
    amounts.erase(*min_element(amounts.begin(), amounts.end()));
    if (amounts.empty()) {
        cout << "Tie" << endl;
        exit(0);
    }
    int desired = *min_element(amounts.begin(), amounts.end());
    string winner;
    for (pair<string, int> cow: milk) {
        if (cow.second == desired) {
            if (winner.empty())
                winner = cow.first;
            else
                winner = "Tie";
        }
    }
    cout << (winner.empty() ? "Tie" : winner) << endl;
}
