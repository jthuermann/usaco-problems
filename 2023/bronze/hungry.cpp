// USACO 2023 February Contest, Bronze
// Problem 1. Hungry Cow
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1299

#include <iostream>

using namespace std;

int main() {
    int N;
    long long T;
    cin >> N >> T;
    long long amount = 0;
    long long haybales = 0;
    long long last_day = 0;
    for (int i = 0; i < N; i++) {
        long long day;
        int delivery;
        cin >> day >> delivery;
        amount += min(haybales, day - last_day);
        haybales -= min(haybales, day - last_day);
        haybales += delivery;
        last_day = day;
    }
    amount += min(haybales, T+1 - last_day);
    cout << amount << endl;
}
