// USACO 2017 US Open Contest, Bronze
// Problem 2. Bovine Genomics
// http://www.usaco.org/index.php?page=viewproblem2&cpid=736

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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
        set<char> s, p;
        for (string cow: spotty)
            s.insert(cow[i]);
        for (string cow: plain)
            p.insert(cow[i]);
        vector<int> intersection;
        set_intersection(s.begin(), s.end(), p.begin(), p.end(), back_inserter(intersection));
        if (intersection.empty())
            amount++;
    }
    cout << amount;
}
