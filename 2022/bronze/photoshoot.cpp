// USACO 2022 US Open Contest, Bronze
// Problem 1. Photoshoot
// http://usaco.org/index.php?page=viewproblem2&cpid=1227

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int last = -1;
    int swaps = 0;
    for (int i = 0; i < N/2; i++) {
        char a, b;
        cin >> a >> b;
        if (a == b)
            continue;
        if (a == 'G') {
            if (last == -1)
                swaps += 1;
            else if (last == 1)
                swaps += 2;
            last = 0;
        } else {
            last = 1;
        }
    }
    cout << swaps << endl;
}
