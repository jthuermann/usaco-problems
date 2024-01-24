// USACO 2015 US Open, Bronze
// Problem 1. Moocryption
// http://usaco.org/index.php?page=viewproblem2&cpid=545

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    freopen("moocrypt.in", "r", stdin);
    freopen("moocrypt.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<vector<char>> puzzle(N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            char c;
            cin >> c;
            puzzle[y].push_back(c);
        }
    }
    map<char, map<char, int>> count;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (x >= 2)
                if (puzzle[y][x-1] == puzzle[y][x-2] && puzzle[y][x] != puzzle[y][x-1])
                    count[puzzle[y][x]][puzzle[y][x-1]]++;
            if (x >= 2 && y >= 2)
                if (puzzle[y-1][x-1] == puzzle[y-2][x-2] && puzzle[y][x] != puzzle[y-1][x-1])
                    count[puzzle[y][x]][puzzle[y-1][x-1]]++;
            if (y >= 2)
                if (puzzle[y-1][x] == puzzle[y-2][x] && puzzle[y][x] != puzzle[y-1][x])
                    count[puzzle[y][x]][puzzle[y-1][x]]++;
            if (x < M-2 && y >= 2)
                if (puzzle[y-1][x+1] == puzzle[y-2][x+2] && puzzle[y][x] != puzzle[y-1][x+1])
                    count[puzzle[y][x]][puzzle[y-1][x+1]]++;
            if (x < M-2)
                if (puzzle[y][x+1] == puzzle[y][x+2] && puzzle[y][x] != puzzle[y][x+1])
                    count[puzzle[y][x]][puzzle[y][x+1]]++;
            if (x < M-2 && y < N-2)
                if (puzzle[y+1][x+1] == puzzle[y+2][x+2] && puzzle[y][x] != puzzle[y+1][x+1])
                    count[puzzle[y][x]][puzzle[y+1][x+1]]++;
            if (y < N-2)
                if (puzzle[y+1][x] == puzzle[y+2][x] && puzzle[y][x] != puzzle[y+1][x])
                    count[puzzle[y][x]][puzzle[y+1][x]]++;
            if (x >= 2 && y < N-2)
                if (puzzle[y+1][x-1] == puzzle[y+2][x-2] && puzzle[y][x] != puzzle[y+1][x-1])
                    count[puzzle[y][x]][puzzle[y+1][x-1]]++;
        }
    }
    int max_count = 0;
    for (pair<char, map<char, int>> i: count)
        for (pair<char, int> j: i.second)
            if (i.first != 'M' && j.first != 'O')
                max_count = max(max_count, j.second);
    cout << max_count << endl;
}
