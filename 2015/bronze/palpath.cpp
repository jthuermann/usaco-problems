// USACO 2015 US Open, Bronze
// Problem 4. Palindromic Paths
// http://www.usaco.org/index.php?page=viewproblem2&cpid=548

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N;
set<vector<short>> distinct;

set<vector<short>> search1(vector<vector<short>>& field, vector<vector<set<vector<short>>>>& cache, int x, int y) {
    if (cache[y][x].size() > 0)
        return cache[y][x];
    if (x < N-1) {
        for (vector<short> v: search1(field, cache, x+1, y)) {
            v.push_back(field[y][x]);
            cache[y][x].insert(v);
        }
    }
    if (y < N-1) {
        for (vector<short> v: search1(field, cache, x, y+1)) {
            v.push_back(field[y][x]);
            cache[y][x].insert(v);
        }
    }
    return cache[y][x];
}

set<vector<short>> search2(vector<vector<short>>& field, vector<vector<set<vector<short>>>>& cache, int x, int y) {
    if (x + y == N-1) {
        if (x > 0) {
            for (vector<short> v: search2(field, cache, x-1, y)) {
                v.push_back(field[y][x]);
                if (cache[y][x].count(v))
                    distinct.insert(v);
            }
        }
        if (y > 0) {
            for (vector<short> v: search2(field, cache, x, y-1)) {
                v.push_back(field[y][x]);
                if (cache[y][x].count(v))
                    distinct.insert(v);
            }
        }
        return set<vector<short>>();
    } else {
        if (cache[y][x].size() > 0)
            return cache[y][x];
        if (x > 0) {
            for (vector<short> v: search2(field, cache, x-1, y)) {
                v.push_back(field[y][x]);
                cache[y][x].insert(v);
            }
        }
        if (y > 0) {
            for (vector<short> v: search2(field, cache, x, y-1)) {
                v.push_back(field[y][x]);
                cache[y][x].insert(v);
            }
        }
        return cache[y][x];
    }    
}

int main() {
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);
    cin >> N;
    vector<vector<short>> field(N);
    vector<vector<set<vector<short>>>> cache(N, vector<set<vector<short>>>(N));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            char c;
            cin >> c;
            field[y].push_back(c - 'A');
        }
    }
    cache[N-1][N-1].insert({field[N-1][N-1]});
    cache[0][0].insert({field[0][0]});
    for (int x = 0; x < N; x++) {
        search1(field, cache, x, N-1-x);
        search2(field, cache, x, N-1-x);
    }
    cout << distinct.size() << endl;
}
