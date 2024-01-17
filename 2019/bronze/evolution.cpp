// USACO 2019 US Open Contest, Bronze
// Problem 3. Cow Evolution
// http://www.usaco.org/index.php?page=viewproblem2&cpid=941

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

bool split(vector<set<int>>& evolutions) {
    if (evolutions.empty() || evolutions.size() == 1)
        return true;
    set<int> intersect(evolutions[0].begin(), evolutions[0].end());
    for (const set<int>& evolution: evolutions) {
        set<int> cp(intersect.begin(), intersect.end());
        intersect.clear();
        set_intersection(cp.begin(), cp.end(), evolution.begin(), evolution.end(), inserter(intersect, intersect.begin()));
    }
    for (set<int>& evolution: evolutions) {
        for (int c: intersect)
            evolution.erase(c);
    }
    set<int> smallest {};
    for (const set<int>& s: evolutions)
        if (!s.empty() && (s.size() < smallest.size() || smallest.empty()))
            smallest = s;
    vector<set<int>> a, b;
    for (const set<int>& evolution: evolutions) {
        bool contains = true;
        for (const int& s: smallest)
            if (!evolution.count(s))
                contains = false;
        if (contains)
            a.push_back(evolution);
        else
            b.push_back(evolution);
    }
    set<int> c_a, c_b;
    for (const set<int>& set_a: a)
        for (const int& s: set_a)
            c_a.insert(s);
    for (const set<int>& set_b: b)
        for (const int& s: set_b)
            c_b.insert(s);
    set<int> failing;
    set_intersection(c_a.begin(), c_a.end(), c_b.begin(), c_b.end(), inserter(failing, failing.begin()));
    if (failing.empty()) {
        if (!split(a))
            return false;
        if (!split(b))
            return false;
    } else {
        return false;
    }
    return true;
}

int main() {
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    int N;
    cin >> N;
    vector<string> characteristics;
    vector<set<int>> evolutions;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        set<int> chars;
        for (int j = 0; j < K; j++) {
            string c;
            cin >> c;
            int index = find(characteristics.begin(), characteristics.end(), c) - characteristics.begin();
            if (index == characteristics.size())
                characteristics.push_back(c);
            chars.insert(index);
        }
        evolutions.push_back(chars);
    }
    if (split(evolutions))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
