// USACO 2023 US Open Contest, Bronze
// Problem 3. Rotate and Shift
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1325

#include <iostream>
#include <vector>

using namespace std;

void apply_moves(vector<int>& arr, vector<int>& moves) {
    vector<int> cp(arr.begin(), arr.end());
    for (int i = 0; i < moves.size(); i++)
        arr[moves[i]] = cp[i];
}

int main() {
    int N, K, T;
    cin >> N >> K >> T;
    vector<int> rotate(K);
    for (int i = 0; i < K; i++)
        cin >> rotate[i];
    vector<int> cows(N);
    for (int i = 0; i < N; i++)
        cows[i] = i;
    vector<int> move_N(N, -1);
    for (int i = 0; i < K; i++) {
        int length = ((i == K-1) ? N : rotate[i+1]) - rotate[i];
        for (int j = rotate[i]; j < rotate[i] + length; j++)
            move_N[j] = (j + (T-(j-rotate[i]) + length - 1) / length * length) % N;
    }
    apply_moves(cows, move_N);
    for (int i = 0; i < N; i++) {
        cout << cows[i];
        if (i != N-1)
            cout << " ";
    }
    cout << endl;
}
