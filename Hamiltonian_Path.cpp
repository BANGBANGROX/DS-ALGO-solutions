//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        vector<vector<bool>> dp(n, vector<bool>(1 << n));
        vector<vector<bool>> adjMatrix(n, vector<bool>(1 << n));

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjMatrix[u - 1][v - 1] = true;
            adjMatrix[v - 1][u - 1] = true;
        }

        for (int i = 0; i < n; ++i) {
            dp[i][1 << i] = true;
        }

        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) > 0) {
                    for (int k = 0; k < n; ++k) {
                        if ((i & (1 << k)) > 0 && 
                            adjMatrix[k][j] && k != j && dp[k][i ^ (1 << j)]) {
                            dp[j][i] = true;
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (dp[i][(1 << n) - 1]) return true;
        }

        return false;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N, M, X, Y;
        cin >> N >> M;
        vector<vector<int>> Edges;
        for (int i = 0; i < M; i++)
        {
            cin >> X >> Y;
            Edges.push_back({ X,Y });
        }
        Solution obj;
        if (obj.check(N, M, Edges)) {
            cout << "1" << endl;
        }
        else
            cout << "0" << endl;
    }
}
// } Driver Code Ends