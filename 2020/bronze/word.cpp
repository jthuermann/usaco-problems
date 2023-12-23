// USACO 2020 January Contest, Bronze
// Problem 1. Word Processor
// http://www.usaco.org/index.php?page=viewproblem2&cpid=987

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    int line = 0;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        int length = word.length();
        if (line == 0) {
            cout << word;
            line = length;
        } else if (line + length <= K) {
            cout << " " << word;
            line += length;
        } else {
            cout << endl << word;
            line = length;
        }
    }
}
