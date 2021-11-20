// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:

	const int mod = 1e9 + 7;

	int MinimumWalk(vector<vector<int>>& graph, int u, int v, int k) {
		// Code here
		int n = graph.size();
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1)));

		for (int e = 0; e <= k; ++e) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i == j && e == 0) dp[i][j][e] = 1;
					if (graph[i][j] && e == 1) dp[i][j][e] = 1;
					if (e > 1) {
						for (int a = 0; a < n; ++a) {
							if (graph[i][a]) {
								dp[i][j][e] = (dp[i][j][e] + dp[a][j][e - 1]) % mod;
							}
						}
					}
				}
			}
		}

		return dp[u][v][k];
	}

};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
