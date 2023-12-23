// USACO 2016 January Contest, Bronze
// Problem 3. Mowing the Field
// http://www.usaco.org/index.php?page=viewproblem2&cpid=593

#include <iostream>
#include <map>

using namespace std;

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int N;
    cin >> N;
    map<pair<int, int>, int> last_visited;
    pair<int, int> position = make_pair(0, 0);
    int time = 0;
    last_visited.insert({position, time});
    int x = -1;
    for (int i = 0; i < N; i++) {
        char direction;
        int steps;
        cin >> direction >> steps;
        for (int j = 0; j < steps; j++) {
            switch (direction) {
                case 'N': {
                    position.second++;
                    break;
                }
                case 'E': {
                    position.first++;
                    break;
                }
                case 'S': {
                    position.second--;
                    break;
                }
                case 'W': {
                    position.first--;
                    break;
                }
            }
            time++;
            if (last_visited.count(position)) {
                int difference = time - last_visited.find(position)->second;
                if (x == -1 || difference < x)
                    x = difference;
                last_visited.find(position)->second = time;
            } else {
                last_visited.insert({position, time});
            }

        }
    }
    cout << x;
}
