// USACO December 2020 Contest, Bronze
// Problem 2. Daisy Chains
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1060

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> petals(N);
    int amount = 0;
    for (int i = 0; i < N; i++) {
        cin >> petals[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += petals[k];
            double average = sum / (double) (j - i + 1);
            for (int k = i; k <= j; k++)
                if (petals[k] == average) {
                    amount++;
                    break;
                }
        }
    }
    cout << amount;
}
