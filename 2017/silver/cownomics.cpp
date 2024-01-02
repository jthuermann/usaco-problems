// USACO 2017 US Open Contest, Silver
// Problem 2. Bovine Genomics
// http://www.usaco.org/index.php?page=viewproblem2&cpid=739

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<string> spotty(N);
    vector<string> plain(N);
    for (int i = 0; i < N; i++)
        cin >> spotty[i];
    for (int i = 0; i < N; i++)
        cin >> plain[i];
    int amount = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                set<tuple<char, char, char>> s, p;
                for (string cow: spotty)
                    s.insert(make_tuple(cow[i], cow[j], cow[k]));
                for (string cow: plain)
                    p.insert(make_tuple(cow[i], cow[j], cow[k]));
                vector<tuple<char, char, char>> intersection;
                set_intersection(s.begin(), s.end(), p.begin(), p.end(), back_inserter(intersection));
                if (intersection.empty())
                    amount++;
            }
        }
    }
    cout << amount;
}
