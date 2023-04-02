#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

public:
    ll distinctNames(vector<string>& ideas) {
         unordered_set<string> suffixes[26];
         ll ans = 0;

         for (string s : ideas) {
             suffixes[s[0] - 'a'].insert(s.substr(1));
         }

         for (int i = 0; i < 26; ++i) {
             for (int j = i + 1; j < 26; ++j) {
                 ll mutual = 0;
                 for (const string& s : suffixes[i]) {
                     if (suffixes[j].find(s) != suffixes[j].end()) {
                         ++mutual;
                     }
                 }
                 ans += 2 * ((int) suffixes[i].size() - mutual) *
                         ((int) suffixes[j].size() - mutual);
             }
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
         vector<string> ideas(n);
         for (string &s : ideas) {
             cin >> s;
         }

         Solution solution;
         cout << solution.distinctNames(ideas) << endl;
    }

    return 0;
}
