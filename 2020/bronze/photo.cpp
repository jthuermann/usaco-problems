// USACO 2020 January Contest, Bronze
// Problem 2. Photoshoot
// http://usaco.org/index.php?page=viewproblem2&cpid=548

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> b(N-1);
    for (int i = 0; i < N-1; i++)
        cin >> b[i];
    for (int first = 1; first <= min(b[0]-1, N); first++) {
        vector<bool> used(N, false);
        used[first-1] = true;
        vector<int> a {first};
        bool fail = false;
        for (int sum: b) {
            int next = sum - a[a.size() - 1];
            if (next > N || next < 1 || used[next - 1]) {
                fail = true;
                break;
            }
            a.push_back(sum - a[a.size() - 1]);
            used[a[a.size() - 1] - 1] = true;
        }
        if (!fail) {
            for (int i = 0; i < N; i++) {
                cout << a[i];
                if (i != N-1)
                    cout << " ";
            }
            cout << endl;
            exit(0);
        }
    }
}
