// USACO 2015 US Open, Bronze
// Problem 2. Bessie Gets Even
// http://usaco.org/index.php?page=viewproblem2&cpid=546

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int bitcount(int b) {
    int count = 0;
    while (b) {
        if (b & 1)
            count++;
        b = b >> 1;
    }
    return count;
}

int main() {
    freopen("geteven.in", "r", stdin);
    freopen("geteven.out", "w", stdout);
    int N;
    cin >> N;
    vector<char> variables {'B', 'E', 'S', 'I', 'G', 'O', 'M'};
    vector<pair<int, int>> count(variables.size());
    for (int i = 0; i < N; i++) {
        char c;
        int value;
        cin >> c >> value;
        int index = find(variables.begin(), variables.end(), c) - variables.begin();
        if (value % 2 == 0)
            count[index].first++;
        else
            count[index].second++;
    }
    int amount = 0;
    for (int i = 0; i < 1 << variables.size(); i++) {
        if (bitcount(i & 9) % 2 && bitcount(i & 54) % 2 && bitcount(i & 64) % 2)
            continue;
        int possibilities = 1;
        for (int j = 0; j < variables.size(); j++) {
            if (i & 1 << j)
                possibilities *= count[j].second;
            else
                possibilities *= count[j].first;
        }
        amount += possibilities;
    }
    cout << amount << endl;
}
