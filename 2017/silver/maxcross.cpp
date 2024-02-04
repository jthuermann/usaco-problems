// USACO 2017 February Contest, Silver
// Problem 2. Why Did the Cow Cross the Road II
// http://www.usaco.org/index.php?page=viewproblem2&cpid=715

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int N, K, B;
    cin >> N >> K >> B;
    vector<bool> signal(N, 0);
    for (int i; cin >> i;)
        signal[i-1] = true;
    vector<int> sums;
    sums.push_back(0);
    for (int i: signal)
        sums.push_back(sums[sums.size() - 1] + i);
    int min_fix = 999999999;
    for (int i = 0; i < sums.size() - K; i++)
        min_fix = min(min_fix, sums[i+K] - sums[i]);
    cout << min_fix << endl;
}
