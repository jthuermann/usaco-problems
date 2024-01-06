// USACO 2023 January Contest, Bronze
// Problem 2. Air Cownditioning II
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1276

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<tuple<int, int, int, int>> conditioners;
vector<tuple<int, int, int>> cows;

int search(int index, vector<tuple<int, int, int, int>>& curr) {
    if (index == conditioners.size()) {
        vector<int> cooling(100, 0);
        int cost = 0;
        for (auto conditioner: curr) {
            int a, b, p, m;
            tie(a, b, p, m) = conditioner;
            for (int i = a; i <= b; i++)
                cooling[i] += p;
            cost += m;
        }
        bool fail = false;
        for (auto cow: cows) {
            int s, t, c;
            tie(s, t, c) = cow;
            for (int i = s; i <= t; i++)
                if (cooling[i] < c)
                    fail = true;
        }
        return fail ? 999999999 : cost;
    }
    int a = search(index+1, curr);
    curr.push_back(conditioners[index]);
    int b = search(index+1, curr);
    curr.pop_back();
    return min(a, b);
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        cows.push_back(make_tuple(s-1, t-1, c));
    }
    for (int i = 0; i < M; i++) {
        int a, b, p, m;
        cin >> a >> b >> p >> m;
        conditioners.push_back(make_tuple(a-1, b-1, p, m));
    }
    vector<tuple<int, int, int, int>> curr;
    cout << search(0, curr) << endl;
}