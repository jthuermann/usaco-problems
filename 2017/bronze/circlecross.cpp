// USACO 2017 February Contest, Bronze
// Problem 2. Why Did the Cow Cross the Road II
// https://usaco.org/index.php?page=viewproblem2&cpid=712

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string s;
    cin >> s;
    int amount = 0;
    for (char c = 65; c < 65+26; c++) {
        int index1 = s.find(c);
        int index2 = s.find(c, index1+1);
        if (index1 + 1 == index2)
            continue;
        string between = s.substr(index1+1, index2-index1-1);
        for (char d = 65; d < 65+26; d++)
            if (count(between.begin(), between.end(), d) == 1) {
                amount++;
            }
    }
    cout << amount/2;
}
