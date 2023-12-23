// USACO 2018 December Contest, Bronze
// Problem 1. Mixing Milk
// http://www.usaco.org/index.php?page=viewproblem2&cpid=855
 
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
    long long ma, mb, mc, ca, cb, cc;
    freopen("mixmilk.in", "r", stdin);
    cin >> ca >> ma >> cb >> mb >> cc >> mc;
    const long long capacities[3] = {ca, cb, cc};
    long long milk[3] = {ma, mb, mc}; 
    for (int i = 0; i < 100; i++) {
        long long amount = min(milk[i%3], capacities[(i+1)%3] - milk[(i+1)%3]);
        milk[i%3] -= amount;
        milk[(i+1)%3] += amount;
    }
    freopen("mixmilk.out", "w", stdout);
    cout << milk[0] << endl << milk[1] << endl << milk[2] << endl;
}
