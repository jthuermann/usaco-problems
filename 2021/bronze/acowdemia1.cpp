// USACO 2021 US Open, Bronze
// Problem 1. Acowdemia I
// http://usaco.org/index.php?page=viewproblem2&cpid=1131

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> citations(N);
    for (int i = 0; i < N; i++)
        cin >> citations[i];
    sort(citations.begin(), citations.end(), cmp);
    int sum = 0;
    int j = 0;
    for (; j < N; j++) {
        if (citations[j] >= j+1)
            continue;
        break;
    }
    for (int i = 0; L > 0 && i < N; i++) {
        if (citations[i] == j)
            citations[i]++, L--;
    }
    for (int i = 0; i < N; i++) {
        if (citations[i] >= i+1)
            continue;
        cout << i << endl;
        exit(0);
    }
    cout << N << endl;
}
