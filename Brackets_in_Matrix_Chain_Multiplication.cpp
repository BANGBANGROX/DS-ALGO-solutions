// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<vector<pair<string, int>>> dp;

    pair<string, int> matrixChainOrderUtil(int p[], int n, int i, int j) {
        if (i == j) return { "" + char(i - 1 + 'A'),0 };

        if (dp[i][j].second != -1) return dp[i][j];

        int ans = INT_MAX;
        string s("");

        for (int k = i; k < j; ++k) {
            pair<string, int> p1 = matrixChainOrderUtil(p, n, i, k);
            pair<string, int> p2 = matrixChainOrderUtil(p, n, k + 1, j);
            int current = p[i - 1] * p[k] * p[j] + p1.second + p2.second;
            if (current <= ans) {
                ans = current;
                s = p1.first + p2.first;
            }
        }

        return dp[i][j] = { '(' + s + ')',ans };
    }

public:
    string matrixChainOrder(int p[], int n) {
        // code here
        dp = vector<vector<pair<string, int>>>(n, vector<pair<string, int>>(n, { "",-1 }));

        return matrixChainOrderUtil(p, n, 1, n - 1).first;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* p = new int[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        Solution ob;
        cout << ob.matrixChainOrder(p, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends