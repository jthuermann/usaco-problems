// USACO 2015 December Contest, Bronze
// Problem 3. Contaminated Milk
// http://www.usaco.org/index.php?page=viewproblem2&cpid=569

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    int N, M, D, S;
    cin >> N >> M >> D >> S;
    vector<vector<pair<int, int>>> drinks(N);
    vector<pair<int, int>> sick;
    for (int i = 0; i < D; i++) {
        int p, m, t;
        cin >> p >> m >> t;
        drinks[p-1].push_back(make_pair(m-1, t));
    }
    for (int i = 0; i < S; i++) {
        int p, t;
        cin >> p >> t;
        sick.push_back(make_pair(p-1, t));
    }
    int medicine = 0;
    for (int i = 0; i < M; i++) {
        bool passing = false;
        for (pair<int, int> sickness: sick) {
            passing = false;
            for (pair<int, int> drink: drinks[sickness.first]) {
                if (drink.first == i && drink.second < sickness.second) {
                    passing = true;
                    break;
                }
            }
            if (!passing)
                break;
        }
        if (!passing)
            continue;
        else {
            int persons = 0;
            for (vector<pair<int, int>> person: drinks) {
                if (find_if(person.begin(), person.end(), [i](pair<int, int> drink){return drink.first == i;}) != person.end())
                    persons++;
            }
            medicine = max(medicine, persons);
        }
    }
    cout << medicine;
}