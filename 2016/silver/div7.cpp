// USACO 2016 January Contest, Silver
// Problem 2. Subsequence Summing to Sevens
// http://www.usaco.org/index.php?page=viewproblem2&cpid=595

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int N;
    cin >> N;
    int prev = 0;
    vector<int> first_mod(7, -1);
    int largest_group = 0;
    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        id %= 7;
        if (first_mod[(id + prev) % 7] == -1) {
            if ((id + prev) % 7 == 0)
                largest_group = max(largest_group, i+1);
            else
                first_mod[(id + prev) % 7] = i;
        } else {
            largest_group = max(largest_group, i - first_mod[(id + prev) % 7]);
        }
        prev += id;
    }
    cout << largest_group << endl;
}