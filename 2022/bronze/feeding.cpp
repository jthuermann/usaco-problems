// USACO 2022 December Contest, Bronze
// Problem 2. Feeding the Cows
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1252

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<char, pair<int, int>> a, pair<char, pair<int, int>> b) {
    return a.second.second - a.second.first < b.second.second - b.second.first;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        vector<char> cows(N);
        vector<pair<char, pair<int, int>>> placements;
        for (int j = 0; j < N; j++)
            cin >> cows[j];
        for (int j = 0; j < N; j++) {
            if (cows[j] != 'G')
                continue;
            int first = j, last;
            for (; j <= first + 2*K; j++) {
                if (j < N && cows[j] == 'G')
                    last = j;
            }
            j--;
            placements.push_back(make_pair('G', make_pair(last - K, first + K)));
        }
        for (int j = 0; j < N; j++) {
            if (cows[j] != 'H')
                continue;
            int first = j, last;
            for (; j <= first + 2*K; j++) {
                if (j < N && cows[j] == 'H')
                    last = j;
            }
            j--;
            placements.push_back(make_pair('H', make_pair(last - K, first + K)));
        }
        sort(placements.begin(), placements.end());
        int amount = 0;
        vector<char> planting(N, '.');
        for (pair<char, pair<int, int>> p: placements) {
            for (int j = p.second.first; j <= p.second.second; j++)
                if (planting[j] == '.') {
                    amount++;
                    planting[j] = p.first;
                    break;
                }
        }
        cout << amount << endl;
        for (char c: planting)
            cout << c;
        cout << endl;
    }
}
