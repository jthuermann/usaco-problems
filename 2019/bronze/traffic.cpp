// USACO 2019 February Contest, Bronze
// Problem 3. Measuring Traffic
// http://www.usaco.org/index.php?page=viewproblem2&cpid=917

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int N;
    cin >> N;
    vector<tuple<string, int, int>> sensors;
    for (int i = 0; i < N; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        sensors.push_back(make_tuple(s, a, b));
    }
    int min_cars = -999999999;
    int max_cars =  999999999;
    for (int i = N-1; i >= 0; i--) {
        string s;
        int a, b;
        tie(s, a, b) = sensors[i];
        if (s == "none") {
            min_cars = max(min_cars, a);
            max_cars = min(max_cars, b);
        } else if (s == "off") {
            min_cars += a;
            max_cars += b;
        } else if (s == "on") {
            min_cars = max(0, min_cars - b);
            max_cars = max(0, max_cars - a);
        }
    }
    cout << min_cars << " " << max_cars << endl;
    min_cars = -999999999;
    max_cars =  999999999;
    for (int i = 0; i < N; i++) {
        string s;
        int a, b;
        tie(s, a, b) = sensors[i];
        if (s == "none") {
            min_cars = max(min_cars, a);
            max_cars = min(max_cars, b);
        } else if (s == "on") {
            min_cars += a;
            max_cars += b;
        } else if (s == "off") {
            min_cars = max(0, min_cars - b);
            max_cars = max(0, max_cars - a);
        }
    }
    cout << min_cars << " " << max_cars << endl;
}
