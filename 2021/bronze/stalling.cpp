// USACO 2021 January Contest, Bronze
// Problem 3. Just Stalling
// http://usaco.org/index.php?page=viewproblem2&cpid=1035

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> heights(N), limits(N);
    for (int i = 0; i < N; i++)
        cin >> heights[i];
    for (int i = 0; i < N; i++)
        cin >> limits[i];
    sort(heights.begin(), heights.end());
    sort(limits.begin(), limits.end());
    long long possibilities = 1;
    for (int i = 0; i < N; i++) {
        int smaller = 0;
        for (int j = 0; j < N; j++)
            if (heights[j] <= limits[i])
                smaller++;
            else
                break;
        possibilities *= (smaller - i);
    }
    cout << possibilities << endl;
}
