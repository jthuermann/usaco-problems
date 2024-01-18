// USACO 2018 February Contest, Bronze
// Problem 3. Taming the Herd
// http://www.usaco.org/index.php?page=viewproblem2&cpid=809

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> log(N, -1);
    log[0] = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (log[i] == -1)
            log[i] = a;
        for (int j = 1; j <= a; j++) {
            if (log[i-j] != -1 && log[i-j] != a-j) {
                cout << -1 << endl;
                exit(0);
            } else {
                log[i-j] = a - j;
            }
        }
    }
    int min = 0, max = 0;
    for (int i: log) {
        if (i == 0) {
            min++;
            max++;
        }
        if (i == -1)
            max++;
    }
    cout << min << " " << max << endl; 
}