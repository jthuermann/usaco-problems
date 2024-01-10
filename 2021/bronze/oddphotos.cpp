// USACO January Contest, Bronze
// Problem 2. Even More Odd Photos
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1084

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int even = 0, odd = 0;
    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        if (id % 2 == 0)
            even++;
        else
            odd++;
    }
    while (even < odd) {
        if (odd < 2)
            break;
        else {
            odd -= 2;
            even++;
        }
    }
    cout << (odd*2 + (even > odd ? 1 : 0)) << endl;
}
