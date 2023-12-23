// USACO 2019 January Contest, Bronze
// Problem 1. Shell Game
// http://www.usaco.org/index.php?page=viewproblem2&cpid=891
 
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int N;
    cin >> N;
    vector<tuple<int,int,int>> swaps;
    for (int i = 0; i < N; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        swaps.push_back(make_tuple(a, b, g));
    }
    int max_score = -1;
    for (int initial = 1; initial < 4; initial++) {
        int current = initial;
        int score = 0;
        for (tuple<int, int, int> swap: swaps) {
            if (get<0>(swap) == current) {
                current = get<1>(swap);
            } else if (get<1>(swap) == current) {
                current = get<0>(swap);
            }
            if (get<2>(swap) == current) {
                score++;
            }
        }
        if (score > max_score) {
            max_score = score;
        }
    }
    cout << max_score;
}
