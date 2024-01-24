// USACO 2021 December Contest, Bronze
// Problem 1. Lonely Photo
// http://usaco.org/index.php?page=viewproblem2&cpid=1155

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    char last = -1;
    vector<long long> consecutive;
    consecutive.push_back(0);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == last || last == -1)
            consecutive[consecutive.size() - 1]++;
        else
            consecutive.push_back(1);
        last = c;
    }
    long long amount = 0;
    for (int i = 0; i < consecutive.size(); i++) {
        long long front = (i > 0) ? consecutive[i-1] : 0;
        long long back = (i < N-1) ? consecutive[i+1] : 0;
        amount += max(front - 1, 0ll) + max(back - 1, 0ll);
        if (consecutive[i] == 1) {
            amount += front*back;
        }
    }
    cout << amount << endl;
}
