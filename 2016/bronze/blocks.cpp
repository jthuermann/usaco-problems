// USACO 2016 December Contest, Bronze
// Problem 2. Block Game
// http://www.usaco.org/index.php?page=viewproblem2&cpid=664

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<string, string>> cards;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        cards.push_back(make_pair(a, b));
    }
    for (char c = 97; c < 97+26; c++) {
        int sum = 0;
        for (auto card: cards) {
            sum += max(count(card.first.begin(), card.first.end(), c), count(card.second.begin(), card.second.end(), c));
        }
        cout << sum << endl;
    }
}
