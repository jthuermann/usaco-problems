// USACO 2020 February Contest, Bronze
// Problem 3. Swapity Swap
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1013

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    int A1, A2, B1, B2;
    cin >> A1 >> A2 >> B1 >> B2;
    A1--, A2--, B1--, B2--;
    vector<int> line, cp;
    for (int i = 1; i <= N; i++) {
        line.push_back(i);
        cp.push_back(i);
    }
    int amount = 0;
    do {
        reverse(line.begin() + A1, line.begin() + A2 + 1);
        reverse(line.begin() + B1, line.begin() + B2 + 1);
        amount++;
    } while (line != cp);
    for (int i = 0; i < K % amount; i++) {
        reverse(line.begin() + A1, line.begin() + A2 + 1);
        reverse(line.begin() + B1, line.begin() + B2 + 1);
    }
    for (int i: line)
        cout << i << endl;
}