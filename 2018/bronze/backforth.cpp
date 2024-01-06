// USACO 2018 December Contest, Bronze
// Problem 3. Back and Forth
// http://www.usaco.org/index.php?page=viewproblem2&cpid=857

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> reads;

void search(vector<pair<int, int>>& buckets, int milk, int day) {
    if (day == 4) {
        reads.insert(milk);
        return;
    }
    for (pair<int, int>& bucket: buckets) {
        vector<int> bucket_sizes;
        if (bucket.second == day%2) {
            if (find(bucket_sizes.begin(), bucket_sizes.end(), bucket.first) == bucket_sizes.end()) {
                bucket.second = (day+1)%2;
                search(buckets, day%2 ? milk + bucket.first : milk - bucket.first, day+1);
                bucket.second = day%2;
                bucket_sizes.push_back(bucket.first);
            }
        }
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector<pair<int, int>> buckets;
    for (int i = 0; i < 20; i++) {
        int bucket;
        cin >> bucket;
        buckets.push_back(make_pair(bucket, i/10));
    }
    search(buckets, 0, 0);
    cout << reads.size() << endl;
}
