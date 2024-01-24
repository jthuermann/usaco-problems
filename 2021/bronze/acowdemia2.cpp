// USACO 2021 US Open, Bronze
// Problem 2. Acowdemia II
// https://usaco.org/index.php?page=viewproblem2&cpid=1132

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    vector<string> names(N);
    for (int i = 0; i < N; i++)
        cin >> names[i];
    vector<string> sorted(names.begin(), names.end());
    sort(sorted.begin(), sorted.end());
    map<string, map<string, int>> relations;
    for (int i = 0; i < K; i++) {
        vector<string> past, curr;
        int last_index = -1;
        for (int j = 0; j < N; j++) {
            string name;
            cin >> name;
            int index = find(sorted.begin(), sorted.end(), name) - sorted.begin();
            if (index < last_index) {
                for (string c: curr)
                    past.push_back(c);
                curr.clear();
            }
            curr.push_back(name);
            for (string p: past) {
                relations[name][p] = 1;
                relations[p][name] = 0;
            }
            last_index = index;
        }
    }
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (j == k) {
                cout << 'B';
            } else if (!relations[names[j]].count(names[k])) {
                cout << '?';
            } else {
                cout << relations[names[j]][names[k]];
            }
        }
        cout << endl;
    }
}
