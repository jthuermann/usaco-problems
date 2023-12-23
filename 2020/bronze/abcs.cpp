// USACO 2020 December Contest, Bronze
// Problem 1. Do You Know Your ABCs?
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1059

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers(7);
    for (int i = 0; i < 7; i++)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());
    cout << numbers[0] << " " << numbers[1] << " " << numbers[6] - numbers[0] - numbers[1];
}
