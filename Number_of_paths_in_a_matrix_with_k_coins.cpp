//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    typedef long long ll;

    vector<vector<vector<ll>>> dp;
    vector<vector<int>> matrix;
    int n;

    ll numberOfPathsUtil(int x, int y, int k) {
        if (x < 0 || y < 0 || x >= n || y >= n || k < 0) return 0;

        if (x == n - 1 && y == n - 1 && k == matrix[x][y]) return 1;

        if (dp[x][y][k] != -1) return dp[x][y][k];

        return dp[x][y][k] = (numberOfPathsUtil(x + 1, y, k - matrix[x][y]) +
                numberOfPathsUtil(x, y + 1, k - matrix[x][y]));
    }

public:
    ll numberOfPath(int n, int k, vector<vector<int>>& matrix){
        // Code Here
        dp = vector<vector<vector<ll>>>(n, vector<vector<ll>>(n, vector<ll>(k + 1, -1)));
        this->n = n;
        this->matrix = matrix;

        return numberOfPathsUtil(0, 0, k);
    }
};

//{ Driver Code Starts.

int main() {
    Solution obj;
    int i, j, k, n, t;
    cin >> t;
    while (t--) {
        cin >> k >> n;
        vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                cin >> v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends