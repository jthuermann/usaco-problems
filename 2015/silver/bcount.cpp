// USACO 2015 December Contest, Silver
// Problem 3. Breed Counting
// http://www.usaco.org/index.php?page=viewproblem2&cpid=572

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    vector<tuple<int, int, int>> sums {{0, 0, 0}};
    for (int i = 0; i < N; i++) {
        int breed;
        cin >> breed;
        tuple<int, int, int> prev = sums[sums.size() - 1];
        sums.push_back(make_tuple(get<0>(prev) + (breed == 1), get<1>(prev) + (breed == 2), get<2>(prev) + (breed == 3)));
    }
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        int breed1 = get<0>(sums[b]) - get<0>(sums[a-1]);
        int breed2 = get<1>(sums[b]) - get<1>(sums[a-1]);
        int breed3 = get<2>(sums[b]) - get<2>(sums[a-1]);
        cout << breed1 << " " << breed2 << " " << breed3 << endl;
    }
}
