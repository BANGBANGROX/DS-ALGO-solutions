#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> mp;
    unordered_map<string, char> invMp;
    vector<string> words;
    int ind = 0;

    for (int i = 0; i < s.size(); ++i) {
        string word("");
        while (i < s.size() && s[i] != ' ') {
            word += s[i];
            ++i;
        }
        if (word != "") words.push_back(word);
    }

    for (string word : words) cout << word << " ";
    cout << endl;

    for (int i = 0; i < pattern.size(); ++i) {
        if (mp.find(pattern[i]) == mp.end()) {
            if (ind == words.size()) return false;
            if (invMp.find(words[ind]) != invMp.end()) return false;
            mp[pattern[i]] = words[ind];
            invMp[words[ind]] = pattern[i];
            ++ind;
        }
        else if (mp[pattern[i]] != words[ind] || invMp[words[ind]] != pattern[i]) return false;
        else ++ind;
    }

    return ind == words.size();
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        string pattern;
        getline(cin, pattern);

        cout << wordPattern(s, pattern) << endl;
    }

    return 0;
}
