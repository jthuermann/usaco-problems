// USACO 2018 January Contest, Bronze
// Problem 3. Out of Place
// http://www.usaco.org/index.php?page=viewproblem2&cpid=785

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> line;
    for (int i = 0; i < N; i++) {
        int height;
        cin >> height;
        line.push_back(height);
    }
    if (N == 2) {
        cout << (line[0] > line[1] ? 1 : 0) << endl;
        exit(0);
    }
    int index = -1, direction = -1;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (line[0] > line[1] && line[1] < line[2]) {
                index = 0;
                direction = 1;
                break;
            }
            continue;
        } else if (i == N - 1) {
            if (line[N - 2] > line[N - 1] && line[N - 3] < line[N - 2]) {
                index = N - 1;
                direction = -1;
                break;
            }
            continue;
        }
        if (line[i-1] <= line[i+1]) {
            if (line[i] > line[i+1]) {
                index = i;
                direction = 1;
                break;
            } else if (line[i-1] > line[i]) {
                index = i;
                direction = -1;
                break;
            }
        }
    }
    if (index == -1) {
        cout << 0 << endl;
        exit(0);
    }
    int last = -1;
    int swaps = 0;
    int i = index + direction;
    while (true) {
        if (line[i] != last) {
            if ((direction == -1 && line[i] <= line[index]) || (direction == 1 && line[i] >= line[index])) {
                break;
            } else {
                swaps++;
            }
        }
        last = line[i];
        i += direction;
    }
    cout << swaps << endl;
}
