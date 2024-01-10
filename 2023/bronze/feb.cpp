// USACO 2023 US Open Contest, Bronze
// Problem 3. FEB
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1323

#include <iostream>
#include <vector>

using namespace std;

struct Possibilities {
    int min, max, selector;
};

void update(int f, bool first_last, Possibilities& p) {
    if (f == 0)
        return;
    if (first_last) {
        p.max += abs(f);
        p.selector = 2;
    } else if ((abs(f % 2) == 0 && f > 0) || (abs(f % 2) == 1 && f < 0)) {
        p.min += 1;
        p.max += (abs(f)/2)*2 + 1;
        if (p.selector != 2)
            p.selector = !p.selector;
    } else {
        p.max += ((abs(f)+1)/2)*2;
    }
}

int main() {
    int N;
    cin >> N;
    int excitement = 0;
    vector<int> grouped_f {0};
    char c, last = 'X';
    for (int i = 0; i < N; i++) {
        cin >> c;
        if (c == 'F') {
            grouped_f[grouped_f.size() - 1]++;
        } else if (grouped_f.back() || i == 0) {
            if (last != c)
                grouped_f[grouped_f.size() - 1] *= -1;
            grouped_f.push_back(0);
            last = c;
        } else if (c == last) {
            excitement++;
        } else {
            last = c;
        }
    }
    Possibilities p = {excitement, excitement, excitement%2};
    for (int f = 0; f < grouped_f.size(); f++) {
        update(grouped_f[f], (f == 0) || (f+1 == grouped_f.size()), p);
    }
    if (grouped_f[0] == N)
        p.max--;
    if (p.selector == 2) {
        cout << p.max - p.min + 1 << endl;
        for (int i = p.min; i <= p.max; i++)
            cout << i << endl;
    } else {
        cout << (p.max - p.min) / 2 + 1 << endl;
        for (int i = p.min; i <= p.max; i += 2)
            cout << i << endl;
    }
}
