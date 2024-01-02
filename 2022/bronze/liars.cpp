// USACO 2022 US Open Contest, Bronze
// Problem 2. Counting Liars
// http://usaco.org/index.php?page=viewproblem2&cpid=1228

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<char, int>> claims;
    for (int i = 0; i < N; i++) {
        char direction; int number;
        cin >> direction >> number;
        claims.push_back(make_pair(direction, number));
    }
    int min_liars = 1000;
    for (pair<char, int> position: claims) {
        int liars = 0;
        for (pair<char, int> claim: claims) {
            if (claim.first == 'L' && position.second > claim.second)
                liars++;
            if (claim.first == 'G' && position.second < claim.second)
                liars++;
        }
        min_liars = min(min_liars, liars);
    }
    cout << min_liars;
}
