#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    string s1;
    string s2;
    int m;
    int n;

    int minimumDeleteSumHandler(int i, int j) {
        if (dp[i + m][j + n] != -1) {
            return dp[i + m][j + n];
        }

        if (i < 0 && j < 0) {
            return dp[i + m][j + n] = 0;
        }

        if (i < 0) {
            return dp[i + m][j + n] = (int)s2[j] + minimumDeleteSumHandler(i, j - 1);
        }

        if (j < 0) {
            return dp[i + m][j + n] = (int)s1[i] + minimumDeleteSumHandler(i - 1, j);
        }

        if (s1[i] == s2[j]) {
            return dp[i + m][j + n] = minimumDeleteSumHandler(i - 1, j - 1);
        }

        return dp[i + m][j + n] = min(s1[i] + minimumDeleteSumHandler(i - 1, j), 
            s2[j] + minimumDeleteSumHandler(i, j - 1));
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        m = (int)s1.size();
        n = (int)s2.size();

        dp = vector<vector<int>>(2 * m + 1, vector<int>(2 * n + 1, -1));

        return minimumDeleteSumHandler(m - 1, n - 1);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;

        Solution solution;
        cout << solution.minimumDeleteSum(s1, s2) << endl;
    }

    return 0;
}