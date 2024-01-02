// USACO 2022 February Contest, Bronze
// Problem 1. Sleeping in Class
// http://usaco.org/index.php?page=viewproblem2&cpid=1203

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<int> sleep(N);
        int sum = 0;
        for (int j = 0; j < N; j++) {
            cin >> sleep[j];
            sum += sleep[j];
        }
        for (int j = N; j >= 1; j--) {
            if (sum % j != 0)
                continue;
            int amount = sum / j;
            int current = 0;
            int merges = 0;
            for (int k: sleep) {
                current += k;
                merges++;
                if (current == amount) {
                    current = 0;
                } else if (current > amount) {
                    merges = -1;
                    break;
                }
            }
            if (merges == -1)
                continue;
            cout << merges - j << endl;
            break;
        }
    }
}
