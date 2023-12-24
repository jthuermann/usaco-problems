// USACO 2019 US Open Contest, Bronze
// Problem 1. Bucket Brigade
// http://www.usaco.org/index.php?page=viewproblem2&cpid=939

#include <iostream>

using namespace std;

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    string farm = "";
    for (int i = 0; i < 10; i++) {
        string line;
        cin >> line;
        farm += line;
    }
    int barn_x, barn_y, lake_x, lake_y, rock_x, rock_y;
    barn_x = farm.find('B') % 10;
    barn_y = farm.find('B') / 10;
    lake_x = farm.find('L') % 10;
    lake_y = farm.find('L') / 10;
    rock_x = farm.find('R') % 10;
    rock_y = farm.find('R') / 10;
    int additional = 0;
    if ((lake_x == barn_x && barn_x == rock_x && !(rock_y > barn_y && rock_y > lake_y) && !(rock_y < barn_y && rock_y < lake_y)) || (lake_y == barn_y && barn_y == rock_y && !(rock_x > barn_x && rock_x > lake_x) && !(rock_x < barn_x && rock_x < lake_x)))
        additional = 2;
    cout << abs(lake_x - barn_x) + abs(lake_y - barn_y) - 1 + additional;
}
