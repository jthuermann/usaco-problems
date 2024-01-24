// USACO 2023 January Contest, Bronze
// Problem 3. Moo Operations
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1277

#include <iostream>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string s;
        cin >> s;
        if (s.find("MOO") != string::npos) {
            cout << s.length() - 3 << endl;
        } else if (s.find("MOM") != string::npos || s.find("OOO") != string::npos) {
            cout << s.length() - 2 << endl;
        } else if (s.find("OOM") != string::npos) {
            cout << s.length() - 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
