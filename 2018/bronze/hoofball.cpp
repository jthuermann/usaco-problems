#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N; i++)
        cin >> cows[i];
    sort(cows.begin(), cows.end());
    vector<int> nearest(N);
    for (int i = 0; i < N; i++) {
        int before = i-1 >= 0 ? cows[i] - cows[i-1] : 999999;
        int after = i+1 < N ? cows[i+1] - cows[i] : 999999;
        if (before <= after)
            nearest[i] = i-1;
        else
            nearest[i] = i+1;
    }
    vector<bool> trained(N, false);
    int balls = 0;
    for (int i = 0; i < N; i++) {
        if (count(nearest.begin(), nearest.end(), i) == 0) {
            balls++;
            int current = i;
            while (!trained[current]) {
                trained[current] = true;
                current = nearest[current];
            }
        }
    }
    balls += count(trained.begin(), trained.end(), false) / 2;
    cout << balls << endl;
}
