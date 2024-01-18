// USACO 2020 February Contest, Bronze
// Problem 2. Mad Scientist
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1012

#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int N;
    string A, B;
    cin >> N >> A >> B;
    int correct_groups = 0, wrong_groups = 0;
    int last = -1;
    for (int i = 0; i < N; i++) {
        if (last == -1 || last != (A[i] == B[i])) {
            last = A[i] == B[i];
            if (A[i] == B[i]) {
                correct_groups++;
            } else {
                wrong_groups++;
            }
        }
    }
    cout << min(wrong_groups, correct_groups+1) << endl;
}