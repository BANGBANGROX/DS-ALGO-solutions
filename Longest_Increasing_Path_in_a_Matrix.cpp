//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<vector<int>> dp;
    vector<vector<int>> matrix;
    int m;
    int n;

    int dfs(int x, int y) {
        if (dp[x][y] != -1) return dp[x][y];

        int dx[] = { -1, 0, 0, 1 };
        int dy[] = { 0, 1, -1, 0 }; 
        int ans = 1;

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newY >= 0 && newX < m && newY < n
                && matrix[newX][newY] > matrix[x][y]) {
                ans = max(ans, dfs(newX, newY) + 1);
            }
        }

        return dp[x][y] = ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix, int m, int n) {
        // Code here
        this->matrix = matrix;
        this->m = m;
        this->n = n;
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        int ans = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == -1) {
                    ans = max(ans, dfs(i, j));
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends