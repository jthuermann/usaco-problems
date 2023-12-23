// USACO 2018 December Contest, Bronze
// Problem 2. The Bucket List
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> used_buckets;
    for (int i = 0; i < N; i++) {
        int from, to, buckets;
        cin >> from >> to >> buckets;
        used_buckets.push_back(make_pair(from, buckets));
        used_buckets.push_back(make_pair(to, -buckets));
    }
    sort(used_buckets.begin(), used_buckets.end(), comp);
    int current = 0;
    int max = 0;
    for (pair<int, int> p: used_buckets) {
        current += p.second;
        if (current > max) {
            max = current;
        }
    }
    cout << max;
}