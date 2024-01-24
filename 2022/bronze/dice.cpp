// USACO 2022 January Contest, Bronze
// Problem 2. Non-Transitive Dice
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1180

#include <iostream>
#include <vector>

using namespace std;

int cmp(vector<int>& dice1, vector<int>& dice2) {
    int a = 0, b = 0;
    for (int i = 0; i < dice1.size(); i++)
        for (int j = 0; j < dice2.size(); j++)
            if (dice1[i] > dice2[j])
                a++;
            else if (dice1[i] < dice2[j])
                b++;
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        vector<int> dice1(4), dice2(4);
        for (int j = 0; j < 4; j++)
            cin >> dice1[j];
        for (int j = 0; j < 4; j++)
            cin >> dice2[j];
        bool done = false;
        for (int a = 1; a <= 10; a++)
            for (int b = 1; b <= 10; b++)
                for (int c = 1; c <= 10; c++)
                    for (int d = 1; d <= 10; d++) {
                        if (done)
                            break;
                        vector<int> dice3 {a, b, c, d};
                        int result = cmp(dice1, dice2) + cmp(dice2, dice3) + cmp(dice3, dice1);
                        if (result == 3 || result == -3) {
                            cout << "yes" << endl;
                            done = true;
                        }
                    }
        if (!done)
            cout << "no" << endl;
    }
}
