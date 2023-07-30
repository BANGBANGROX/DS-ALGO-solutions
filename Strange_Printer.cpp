#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    string s;
    int n;

    int strangePrinterHandler(int left, int right) {
        if (dp[left][right] != -1) return dp[left][right];

        dp[left][right] = n;
        int j = -1;

        for (int i = left; i < right; ++i) {
            if (s[i] != s[right] && j == -1) {
                j = i;
            }
            if (j != -1) {
                dp[left][right] = min(dp[left][right], 
                   strangePrinterHandler(i + 1, right) + strangePrinterHandler(j, i) + 1);
            }
        }

        if (j == -1) dp[left][right] = 0;

        return dp[left][right];
    }

public:
    int strangePrinter(string s) {
        n = (int)s.size();
        this->s = s;
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        return strangePrinterHandler(0, n - 1) + 1;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        Solution solution;
        cout << solution.strangePrinter(s) << endl;
    }
}