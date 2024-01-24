// USACO 2015 US Open, Bronze
// Problem 3. Trapped in the Haybales
// http://usaco.org/index.php?page=viewproblem2&cpid=547

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("trapped.in", "r", stdin);
    freopen("trapped.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> haybales;
    for (int i = 0; i < N; i++) {
        int size, position;
        cin >> size >> position;
        haybales.push_back(make_pair(position, size));
    }
    sort(haybales.begin(), haybales.end());
    long long area = 0;
    int i = 0;
    while (i < N-1) {
        int begin = i, end = i+1;
        bool repeat = true;
        while (repeat) {
            repeat = false;
            int speed = haybales[end].first - haybales[begin].first;
            if (speed > haybales[begin].second) {
                repeat = true;
                begin--;
            }
            if (speed > haybales[end].second) {
                repeat = true;
                end++;
            }
            if (begin < 0 || end >= N)
                break;
        }
        if (!repeat) {
            area += haybales[end].first - haybales[i].first;
            i = end;
        } else {
            i++;
        }
    }
    cout << area << endl;
}
