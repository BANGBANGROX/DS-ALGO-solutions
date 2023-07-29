#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<int>> directions = { {-2, 1}, {1, 2}, {2, 1}, {2, -1},
                {1, -2}, {-1, -2}, {-2, -1}, {-1, 2} };
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n)));
        double answer = 0;

        dp[0][row][column] = 1;

        for (int move = 1; move <= k; ++move) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (vector<int>& direction : directions) {
                        int prevI = i - direction[0];
                        int prevJ = j - direction[1];
                        if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                            dp[move][i][j] += (dp[move - 1][prevI][prevJ] / 8.0);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                answer += dp[k][i][j];
            }
        }

        return answer;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k, row, column;
        cin >> n >> k >> row >> column;

        Solution solution;
        cout << solution.knightProbability(n, k, row, column) << endl;
    }

    return 0;
}