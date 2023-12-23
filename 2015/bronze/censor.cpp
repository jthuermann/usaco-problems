// USACO 2015 February Contest, Bronze
// Problem 1. Censoring
// http://www.usaco.org/index.php?page=viewproblem2&cpid=526

#include <iostream>

using namespace std;

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string text, censored, final;
    cin >> text >> censored;
    for (int i = 0; i < text.length(); i++) {
        final += text[i];
        if (final.length() >= censored.length() && final.substr(final.length() - censored.length()) == censored) {
            final = final.substr(0, final.length() - censored.length());
        }
    }
    cout << final << endl;
}
