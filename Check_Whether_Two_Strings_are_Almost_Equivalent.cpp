#include<bits/stdc++.h>
using namespace std;

bool checkAlmostEquivalent(string word1, string word2) {
    vector<int> freq(26);
    int n = word1.size();

    for (int i = 0; i < n; ++i) {
        ++freq[word1[i] - 'a'];
        --freq[word2[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (abs(freq[i]) > 3) return false;
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string word1, word2;
        cin >> word1 >> word2;

        if (checkAlmostEquivalent(word1, word2)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}
