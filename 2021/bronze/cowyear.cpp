// USACO 2021 February Contest, Bronze
// Problem 1. Year of the Cow
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1107

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    vector<string> years {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    int N;
    cin >> N;
    map<string, pair<int, int>> cows;
    cows["Bessie"] = make_pair(0, 0);
    for (int i = 0; i < N; i++) {
        string cow1, cow2, year, when;
        cin >> cow1 >> when >> when >> when >> year >> cow2 >> cow2 >> cow2;
        int index_new = find(years.begin(), years.end(), year) - years.begin();
        int index_old = cows[cow2].second;
        int offset;
        if (when == "next") {
            if (index_new > index_old)
                offset = index_new - index_old;
            else
                offset = years.size() - index_old + index_new;
        } else {
            if (index_new < index_old)
                offset = index_new - index_old;
            else
                offset = - years.size() + index_new - index_old;
        }
        cows[cow1] = make_pair(cows[cow2].first + offset, index_new);
    }
    cout << abs(cows["Elsie"].first) << endl;
}
