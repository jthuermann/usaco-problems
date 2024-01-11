// USACO 2018 US Open Contest, Bronze
// Problem 3. Family Tree
// http://www.usaco.org/index.php?page=viewproblem2&cpid=833

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string operator * (const string& a, unsigned int b) {
    string ret = "";
    while (b--)
        ret += a;
    return ret;
}

int main() {
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;
    map<string, string> mother;
    for (int i = 0; i < N; i++) {
        string mom, child;
        cin >> mom >> child;
        mother[child] = mom;
    }
    vector<string> mothers_a, mothers_b;
    string current = A;
    while (mother.count(current)) {
        mothers_a.push_back(mother[current]);\
        current = mother[current];
    }
    current = B;
    while (mother.count(current)) {
        mothers_b.push_back(mother[current]);
        current = mother[current];
    }
    const string prefix = "great-";
    if (int index = find(mothers_a.begin(), mothers_a.end(), B) - mothers_a.begin(); index != mothers_a.size()) {
        string relation;
            if (index == 0)
                relation = "mother";
            else
                relation = (relation * (index - 1)) + "grand-mother";
        cout << B << " is the " << relation << " of " << A << endl;
        exit(0);
    }
    if (int index = find(mothers_b.begin(), mothers_b.end(), A) - mothers_b.begin(); index != mothers_b.size()) {
        string relation;
            if (index == 0)
                relation = "mother";
            else
                relation = (prefix * (index - 1)) + "grand-mother";
        cout << A << " is the " << relation << " of " << B << endl;
        exit(0);
    }
    for (int i = 0; i < mothers_a.size(); i++) {
        int index_b = find(mothers_b.begin(), mothers_b.end(), mothers_a[i]) - mothers_b.begin();
        if (index_b == mothers_b.size()) {
            continue;
        } else {
            if (i == 0 && index_b == 0) {
                cout << "SIBLINGS" << endl;
            } else if (i >= 1 && index_b >= 1) {
                cout << "COUSINS" << endl;
            } else if (i > index_b) {
                cout << B << " is the " + (prefix * (i - 1)) + "aunt of " << A << endl;
            } else {
                cout << A << " is the " + (prefix * (index_b - 1)) + "aunt of " << B << endl;
            }
            exit(0);
        }
    }
    cout << "NOT RELATED" << endl;
}
