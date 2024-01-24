// USACO 2022 February Contest, Bronze
// Problem 3. Blocks
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1205

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<set<char>> blocks(4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            char c;
            cin >> c;
            blocks[i].insert(c);
        }
    }
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        bool possible = false;
        sort(blocks.begin(), blocks.end());
        do {
            if (possible)
                break;
            possible = true;
            word.length();
            for (int j = 0; j < word.length(); j++) {
                if (!blocks[j].count(word[j])) {
                    possible = false;
                    break;
                }
            }
        } while (next_permutation(blocks.begin(), blocks.end()));
        cout << (possible ? "YES" : "NO") << endl;
    }
}
