// USACO 2019 January Contest, Bronze
// Problem 3. Guess the Animal
// 

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int N; cin >> N;
    vector<string> properties;
    vector<vector<int>> animals(N);
    for (int i = 0; i < N; i++) {
        string ignored; int count;
        cin >> ignored >> count;
        for (int j = 0; j < count; j++) {
            string property; cin >> property;
            long long index = find(properties.begin(), properties.end(), property) - properties.begin();
            if (index == properties.size())
                properties.push_back(property);
            animals[i].push_back((int) index);
        }
    }
    int max_yes = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int yes = 0;
            for (int a: animals[i])
                if (find(animals[j].begin(), animals[j].end(), a) != animals[j].end())
                    yes++;
            max_yes = max(max_yes, yes);
        }
    }
    cout << max_yes + 1;
}