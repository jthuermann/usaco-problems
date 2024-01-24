// USACO 2022 December Contest, Bronze
// Problem 3. Reverse Engineering
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1253

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool search(set<pair<vector<bool>, bool>>& outputs, int N, set<int>& used) {
    if (outputs.size() == 1 || outputs.size() == 0)
        return true;
    for (int i = 0; i < N; i++) {
        if (used.count(i))
            continue;
        int one = 0, one_count = 0;
        int zero = 0, zero_count = 0;
        for (pair<vector<bool>, bool> output: outputs)
            if (output.first[i] == 0) {
                zero += output.second;
                zero_count++;
            } else {
                one += output.second;
                one_count++;
            }
        int out = -1;
        if (one_count && (one == 0 || one == one_count))
            out = 1;
        else if (zero_count && (zero == 0 || zero == zero_count))
            out = 0;
        if (out != -1) {
            used.insert(i);
            set<pair<vector<bool>, bool>> removed;
            for (pair<vector<bool>, bool> output: outputs) {
                if (output.first[i] == out) {
                    removed.insert(output);
                }
            }
            for (pair<vector<bool>, bool> r: removed)
                outputs.erase(r);
            if (search(outputs, N, used))
                return true;
            for (pair<vector<bool>, bool> r: removed)
                outputs.insert(r);
            used.erase(i);
            break;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        set<pair<vector<bool>, bool>> outputs;
        for (int j = 0; j < M; j++) {
            vector<bool> input;
            for (int k = 0; k < N; k++) {
                char c;
                cin >> c;
                input.push_back(c == '1');
            }
            bool output;
            cin >> output;
            outputs.insert(make_pair(input, output));
        }
        cout << (search(outputs, N, *new set<int>()) ? "OK" : "LIE") << endl;
    }
}
