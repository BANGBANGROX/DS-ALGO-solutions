#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = (int) lcp.size();
        char *result = new char[n];

        result[0] = 'a';

        for (int i = 1; i < n; ++i) {
            char test = 'a';
            bool flag = false;
            for (int j = 0; j < i; ++j) {
                test = max(test, result[j]);
                if (lcp[i][j] > 0) {
                    result[i] = result[j];
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            ++test;
            if (test > 'z') return "";
            result[i] = test;
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (result[i] == result[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (lcp[i][j] != dp[i][j]) return "";
            }
        }

        string ans("");

        for (int i = 0; i < n; ++i) {
            ans += result[i];
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
        vector<vector<int>> lcp(n, vector<int>(n));
        for (vector<int>&x: lcp) {
            for (int &y: x) {
                cin >> y;
            }
        }

        Solution solution;
        cout << solution.findTheString(lcp);
    }
}
