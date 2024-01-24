// USACO 2022 US Open Contest, Bronze
// Problem 3. Alchemy
// http://usaco.org/index.php?page=viewproblem2&cpid=1229

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

bool cmp (int a, int b) {
    return a > b;
}

bool craft(map<int, vector<int>>& recipes, vector<int>& metals, int metal) {
    if (!recipes.count(metal))
        return false;
    for (int ingredient: recipes[metal]) {
        if (metals[ingredient] == 0 && !craft(recipes, metals, ingredient))
            return false;
        metals[ingredient]--;
    }
    metals[metal]++;
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> metals(N);
    for (int i = 0; i < N; i++) {
        cin >> metals[i];
    }
    int K;
    cin >> K;
    map<int, vector<int>> recipes;
    for (int i = 0; i < K; i++) {
        int L, M;
        cin >> L >> M;
        for (int j = 0; j < M; j++) {
            int ingredient;
            cin >> ingredient;
            recipes[L-1].push_back(ingredient-1);
        }
        sort(recipes[L-1].begin(), recipes[L-1].end(), cmp);
    }
    while (craft(recipes, metals, N-1));
    cout << metals[N-1] << endl;
}
