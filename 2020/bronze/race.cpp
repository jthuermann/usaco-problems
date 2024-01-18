// USACO 2020 January Contest, Bronze
// Problem 3. Race
// http://www.usaco.org/index.php?page=viewproblem2&cpid=989

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int K, N;
    cin >> K >> N;
    int max_speed = sqrt(2*K);
    while ((max_speed*max_speed + max_speed)/2 < K)
        max_speed++;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        if (X >= max_speed) {
            cout << max_speed << endl;
            continue;
        }
        int s = X+1;
        while (true) {
            int a = (s*s + s)/2 + ((X+s-1)*(s-X))/2;
            if (a >= K) {
                cout << s + s - X << endl;
                break;
            } else if (a + s + s + 1 > K + X) {
                cout << s + s - X + (K - a) / s + ((K - a)%s == 0 ? 0 : 1) << endl;
                break;
            }
            s++;
        }
    }
}
