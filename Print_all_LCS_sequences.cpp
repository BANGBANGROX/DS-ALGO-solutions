// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<string> ans;
    unordered_set<string> visited;
    map<pair<int, pair<int, string>>, bool> done;
    string s;
    string t;

    void generate(int i, int j, int length, string current) {
        if (length == 0) {
            if (visited.find(current) != visited.end()) return;
            ans.push_back(current);
            visited.insert(current);
            return;
        }

        if (i == (int)s.size() || j == (int)t.size() || done.find({ i,{j,current} }) != done.end()) 
            return;

        done[{i, { j,current }}] = true;

        if (s[i] == t[j]) {
            current.push_back(s[i]);
            generate(i + 1, j + 1, length - 1, current);
            current.pop_back();
        }
        else {
            generate(i + 1, j, length, current);
            generate(i + 1, j + 1, length, current);
            generate(i, j + 1, length, current);
        }
    }

public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        // Code here
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        this->s = s;
        this->t = t;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][j - 1], dp[i - 1][j]));
            }
        }

        int maxLen = dp[m][n];
        string current("");

        generate(0, 0, maxLen, current);

        sort(ans.begin(), ans.end());

        return ans;
    }
};



// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends