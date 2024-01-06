// USACO 2016 January Contest, Bronze
// Problem 2. Angry Cows
// http://www.usaco.org/index.php?page=viewproblem2&cpid=592

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> hay(N);
    for (int i = 0; i < N; i++)
        cin >> hay[i];
    sort(hay.begin(), hay.end());
    int max_hay = 0;
    for (int i = 0; i < N; i++) {
        int h = 1;
        int radius = 1, center = i;
        while (center != 0 && hay[center] - hay[center-1] <= radius) {
            int j = center - 1;
            for (; j >= 0 && hay[center] - hay[j] <= radius; j--)
                h++;
            center = j+1;
            radius++;
        }
        radius = 1, center = i;
        while (center != N-1 && hay[center+1] - hay[center] <= radius) {
            int j = center + 1;
            for (; j <= N-1 && hay[j] - hay[center] <= radius; j++)
                h++;
            center = j-1;
            radius++;
        }
        max_hay = max(max_hay, h);
    }
    cout << max_hay << endl;
}
