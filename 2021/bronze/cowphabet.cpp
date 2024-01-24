// USACO 2021 January Contest, Bronze
// Problem 1. Uddered but not Herd
// http://usaco.org/index.php?page=viewproblem2&cpid=1083

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string alphabet, humming;
    cin >> alphabet >> humming;
    int amount = 0;
    for (int i = 0; i < humming.length(); i++) {
        int index = find(alphabet.begin(), alphabet.end(), humming[i]) - alphabet.begin();
        int prev_index = find(alphabet.begin(), alphabet.end(), humming[i-1]) - alphabet.begin();
        if (index <= prev_index)
            amount++;
    }
    cout << amount << endl;
}
