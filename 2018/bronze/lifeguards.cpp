// USACO 2018 January Contest, Bronze
// Problem 2. Lifeguards
// http://www.usaco.org/index.php?page=viewproblem2&cpid=784

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> from(N), to(N);
    for (int i = 0; i < N; i++)
        cin >> from[i] >> to[i];
    int max_time = 0;
    for (int i = 0; i < N; i++) {
        vector<int> time(1000, 0);
        for (int lifeguard = 0; lifeguard < N; lifeguard++)
            for (int j = from[lifeguard]; j < to[lifeguard]; j++)
                if (lifeguard != i)
                    time[j] = 1;
        int sum = 0;
        for (int j: time)
            sum += j;
        max_time = max(max_time, sum);
    }
    cout << max_time;
}
