// USACO 2018 US Open Contest, Bronze
// Problem 3. Milking Order
// http://www.usaco.org/index.php?page=viewproblem2&cpid=832

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& order, vector<int>& suborder) {
    int index = 0;
    for (int j = 0; j < suborder.size(); j++) {
        if (int k = find(order.begin(), order.end(), suborder[j]) - order.begin(); k != order.size()) {
            if (index > k)
                return false;
            index = k + 1;
        } else {
            index = find(order.begin() + index, order.end(), -1) - order.begin();
            if (index == order.size())
                return false;
            index++;
        }
    }
    return true;
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> order(N, -1);
    vector<int> suborder;
    for (int i = 0; i < M; i++) {
        int m;
        cin >> m;
        suborder.push_back(m-1);
    }
    for (int i = 0; i < K; i++) {
        int cow, position;
        cin >> cow >> position;
        order[position-1] = cow-1;
    }
    if (int i = find(order.begin(), order.end(), 0) - order.begin(); i != N) {
        cout << i+1 << endl;
        exit(0);
    }
    for (int i = 0; i < N; i++) {
        if (order[i] != -1)
            continue;
        order[i] = 0;
        if (check(order, suborder)) {
            cout << i+1 << endl;
            exit(0);
        }
        order[i] = -1;
    }
}
