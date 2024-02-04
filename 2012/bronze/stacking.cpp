// USACO 2012 January Contest, Bronze Division
// Problem 2. Haybale Stacking
// http://www.usaco.org/index.php?page=viewproblem2&cpid=104

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> differences(N, 0);
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        differences[a]++;
        if (b+1 < N)
            differences[b+1]--;
    }
    vector<int> heights;
    int height = 0;
    for (int i = 0; i < N; i++) {
        height += differences[i];
        heights.push_back(height);
    }
    sort(heights.begin(), heights.end());
    cout << heights[N/2] << endl;
}