// USACO 2022 January Contest, Bronze
// Problem 1. Herdle
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1179

#include <iostream>
#include <map>

using namespace std;

const int DIM = 3;

int main() {
    string correct, guess;
    for (int i = 0; i < DIM; i++) {
        string line;
        cin >> line;
        correct += line;
    }
    for (int j = 0; j < DIM; j++) {
        string line;
        cin >> line;
        guess += line;
    }
    map<char, int> correct_count, guess_count;
    for (char c: correct)
        correct_count[c]++;
    for (char g: guess)
        guess_count[g]++;
    int green = 0, yellow = 0;
    for (int i = 0; i < DIM*DIM; i++) {
        if (correct[i] == guess[i]) {
            green++;
            correct_count[correct[i]]--;
            guess_count[guess[i]]--;
        }
    }
    for (pair<char, int> c: correct_count) {
        yellow += min(correct_count[c.first], guess_count[c.first]);
    }
    cout << green << endl;
    cout << yellow << endl;
}
