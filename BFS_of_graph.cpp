#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        vector<bool> vis(n);
        vector<int> res;
        queue<int> q;
        q.push(0);
        res.push_back(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for (int child : adj[node]) {
                if (!vis[child]) {
                    vis[child] = 1;
                    q.push(child);
                    res.push_back(child);
                }
            }
        }

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
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}  