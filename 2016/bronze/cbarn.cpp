// USACO 2016 February Contest, Bronze
// Problem 2. Circular Barn
// http://www.usaco.org/index.php?page=viewproblem2&cpid=616

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> cows;
    for (int i = 0; i < n; i++) {
        int amount;
        cin >> amount;
        cows.push_back(amount);
    }
    int min_distance = 999999999;
    for (int start = 0; start < n; start++) {
        int distance = 0;
        for (int i = 0; i < n; i++) {
            if (i < start)
                distance += cows[i] * (i + n - start);
            else
                distance += cows[i] * (i - start);
        }
        if (distance < min_distance)
            min_distance = distance;
    }
    cout << min_distance << endl;
}
