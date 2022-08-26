#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        unordered_set<string> st;
        vector<string> mapping = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                                  "--", "-.", "---", ".--.", "--.-",
                                  ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                                  "-.--", "--.."};

        for (string &word: words) {
            string res("");
            for (char ch: word) {
                res += mapping[ch - 'a'];
            }
            st.insert(res);
        }

        return (int) st.size();
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<string> words(n);
        for (string &x: words) cin >> x;

        Solution solution;
        cout << solution.uniqueMorseRepresentations(words) << endl;
    }

    return 0;
}