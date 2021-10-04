#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>* adj, vector<int>& vis, vector<int>& res) {
        vis[node] = 1;
        res.push_back(node);

        for (int child : adj[node]) {
            if (!vis[child]) dfs(child, adj, vis, res);
        }
    }

    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<int> res;
        vector<int> vis(n);

        dfs(0, adj, vis, res);

        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int>* adj = new vector<int>[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
  
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}  
