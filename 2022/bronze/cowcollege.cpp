// USACO 2022 December Contest, Bronze
// Problem 1. Cow College
// http://usaco.org/index.php?page=viewproblem2&cpid=1251

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> money(N);
    for (int i = 0; i < N; i++)
        cin >> money[i];
    sort(money.begin(), money.end());
    long long max_money = 0;
    int tuition;
    for (int i = 0; i < money.size(); i++) {
        long long m = (money.size() - i) * money[i];
        if (m > max_money) {
            max_money = m;
            tuition = money[i];
        }
    }
    cout << max_money << " " << tuition << endl;
}
