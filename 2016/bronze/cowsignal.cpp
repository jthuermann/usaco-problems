// USACO 2016 December Contest, Bronze
// Problem 3. The Cow-Signal
// http://www.usaco.org/index.php?page=viewproblem2&cpid=665

#include <iostream>
#include <string>

using namespace std;

int main() {

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < M; i++) {
        string line;
        getline(cin >> ws, line);
        for (int j = 0; j < K; j++) {
            for (char c: line) {
                for (int k = 0; k < K; k++) {
                    cout << c;
                }
            }
            cout << endl;
        }
    }
}
