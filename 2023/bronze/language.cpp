// USACO 2023 US Open Contest, Bronze
// Problem 2. Moo Language
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1324

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, C, P;
        cin >> N >> C >> P;
        vector<string> nouns, intransitive, transitive, conjunctions;
        for (int j = 0; j < N; j++) {
            string word, type;
            cin >> word >> type;
            if (type == "noun")
                nouns.push_back(word);
            else if (type == "intransitive-verb")
                intransitive.push_back(word);
            else if (type == "transitive-verb")
                transitive.push_back(word);
            else if (type == "conjunction")
                conjunctions.push_back(word);
        }
        int size_n = (int) nouns.size();
        int size_i = (int) intransitive.size();
        int size_t = (int) transitive.size();
        int size_c = (int) conjunctions.size();
        size_c = min(size_c, P);
        int x = min(size_i, size_n) + max((size_n - size_i) / 2, 0);
        int max_sentences = min(min(P + size_c, size_t + size_i), x);
        int i_sentences = min(min(size_n, size_i), max_sentences);
        int t = min((size_n - i_sentences) / 2, max_sentences - i_sentences);
        int t_sentences = min(min(size_t, size_n - i_sentences - t), max_sentences);
        if (i_sentences + t_sentences > max_sentences)
            i_sentences = max_sentences - t_sentences;
        int additional_nouns = t_sentences ? min(size_n - i_sentences - t_sentences * 2, C) : 0;
        int conjunctions_used = min((i_sentences + t_sentences) / 2, size_c);
        cout << i_sentences*2 + t_sentences*3 + additional_nouns + conjunctions_used << endl;
        int index_n = 0;
        bool last_conjunction = false;
        for (int j = 0; j < i_sentences; j++) {
            cout << nouns[index_n] << " " << intransitive[j];
            index_n++;
            if (!last_conjunction && conjunctions_used > 0) {
                cout << " " << conjunctions[conjunctions_used-1] << " ";
                conjunctions_used--;
                last_conjunction = true;
            } else {
                cout << ".";
                if (j+1 < i_sentences || t_sentences)
                    cout << " ";
                last_conjunction = false;
            }
        }
        for (int j = 0; j < t_sentences; j++) {
            cout << nouns[index_n] << " " << transitive[j] << " " <<  nouns[index_n+1];
            index_n += 2;
            if (j == 0) {
                for (int k = 0; k < additional_nouns; k++) {
                    cout << ", " << nouns[index_n];
                    index_n++;
                }
            }
            if (!last_conjunction && conjunctions_used > 0) {
                cout << " " << conjunctions[conjunctions_used-1] << " ";
                conjunctions_used--;
                last_conjunction = true;
            } else {
                cout << ".";
                if (j+1 < t_sentences)
                    cout << " ";
                last_conjunction = false;
            }
        }
        cout << endl;
    }
}
