// USACO 2021 February Contest, Bronze
// Problem 3. Clockwise Fence
// http://usaco.org/index.php?page=viewproblem2&cpid=1109

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string fence;
        cin >> fence;
        int x = 0, y = 0;
        int clockwise = 0;
        for (char c: fence) {
            if (c == 'N')
                y++;
            else if (c == 'E')
                x++;
            else if (c == 'S')
                y--;
            else if (c == 'W')
                x--;
            if (x == 0 && y != 0 && (c == 'E' || c == 'W')) {
                if (y < 0)
                    clockwise += (c == 'W') ? 1 : -1;
                else
                    clockwise += (c == 'E') ? 1 : -1;
            }
            if (x == 1 && c == 'E' && y != 0) {
                clockwise += (y > 0) ? 1 : -1;
            }
            if (x == -1 && c == 'W' && y != 0) {
                clockwise += (y < 0) ? 1 : -1;
            }
        }
        if (clockwise > 0)
            cout << "CW" << endl;
        else if (clockwise < 0)
            cout << "CCW" << endl;
    }
}
