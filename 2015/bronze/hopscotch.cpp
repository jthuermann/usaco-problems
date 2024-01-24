#include <iostream>
#include <vector>

using namespace std;

int R, C;

int search(vector<vector<int>>& field, int x, int y) {
    if (x == C-1 && y == R-1)
        return 1;
    int amount = 0;
    for (int X = x+1; X < C; X++)
        for (int Y = y+1; Y < R; Y++)
            if (field[y][x] != field[Y][X])
                amount += search(field, X, Y);
    return amount;
}

int main() {
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    cin >> R >> C;
    vector<vector<int>> field(R);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char color; cin >> color;
            field[i].push_back(color == 'R');
        }
    }
    cout << search(field, 0, 0) << endl;
}
