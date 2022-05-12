// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int maxLevel;

    void dfs(int node, vector<vector<int>>& tree, int level, int parent) {
        maxLevel = max(maxLevel, level);

        for (int child : tree[node]) {
            if (child != parent) {
                dfs(child, tree, level + 1, node);
            }
        }
    }

public:
    int partyHouse(int n, vector<vector<int>>& tree) {
        // code here
        int ans = INT_MAX;

        for (int i = 1; i <= n; ++i) {
            maxLevel = 0;
            dfs(i, tree, 0, -1);
            ans = min(ans, maxLevel);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, x, y;
        cin >> N;
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < N - 1; i++) {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }

        Solution ob;
        cout << ob.partyHouse(N, adj) << "\n";
    }
    return 0;
}  // } Driver Code Ends