#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = (int) pizza.size();
        int n = (int) pizza[0].size();
        const int MOD = (int) 1e9 + 7;
        vector<vector<int>> apples(m + 1, vector<int>(n + 1));
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m,
                vector<int>(n)));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                apples[i][j] = (pizza[i][j] == 'A' ? 1 : 0) + apples[i + 1][j] +
                        apples[i][j + 1] - apples[i + 1][j + 1];
                dp[0][i][j] = apples[i][j] > 0 ? 1 : 0;
            }
        }

        for (int remain = 1; remain < k; ++remain) {
            for (int row = 0; row < m; ++row) {
                for (int col = 0; col < n; ++col) {
                    for (int nextRow = row + 1; nextRow < m; ++nextRow) {
                        if (apples[row][col] - apples[nextRow][col] > 0) {
                            dp[remain][row][col] = (dp[remain][row][col] +
                                    dp[remain - 1][nextRow][col]) % MOD;
                        }
                    }
                    for (int nextCol = col + 1; nextCol < n; ++nextCol) {
                        if (apples[row][col] - apples[row][nextCol]) {
                            dp[remain][row][col] = (dp[remain][row][col] +
                                    dp[remain - 1][row][nextCol]) % MOD;
                        }
                    }
                }
            }
        }

        return dp[k - 1][0][0];
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m;
        cin >> m;
        vector<string> pizza(m);
        for (string &s: pizza) {
            cin >> s;
        }
        int k;
        cin >> k;

        Solution solution;
        cout << solution.ways(pizza, k);
    }

    return 0;
}
