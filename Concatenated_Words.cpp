#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<string> dictionary;

    bool wordBreak(string &word) {
        int n = (int) word.size();
        vector<bool> dp(n + 1);

        dp[0] = true;

        for (int len = 1; len <= n; ++len) {
            for (int i = (len == n ? 1 : 0); i < len; ++i) {
                dp[len] = dp[i] && dictionary.find(word.substr(i, len - i)) != dictionary.end();
                if (dp[len]) break;
            }
        }

        return dp[n];
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        dictionary = unordered_set<string>(words.begin(), words.end());
        vector<string> ans;

        for (string word : words) {
            if (wordBreak(word)) ans.push_back(word);
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
         int n;
         cin >> n;
         vector<string> words(n);
         for (string &s: words) cin >> s;

         Solution solution;
         vector<string> ans = solution.findAllConcatenatedWordsInADict(words);
         for (string &x: ans) cout << x << " ";
         cout << endl;
    }

    return 0;
}
