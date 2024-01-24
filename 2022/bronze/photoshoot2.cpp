// USACO 2022 February Contest, Bronze
// Problem 2. Photoshoot 2
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1204

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    map<int, int> b;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++) {
        int bi;
        cin >> bi;
        b[bi] = i;
    }
    int sorted = -1;
    int modifications = 0;
    for (int cow: a) {
        int index = b[cow];
        if (sorted >= index)
            continue;
        modifications += index - sorted - 1;
        sorted = index;
    }
    cout << modifications << endl;
}
