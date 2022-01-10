// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    vector<int> inTime, lowTime;
    vector<bool> vis;
    int timer, c, d;
    bool ans;

    void dfs(int node, vector<int> adj[], int par) {
        vis[node] = true;
        inTime[node] = lowTime[node] = ++timer;

        for (int child : adj[node]) {
            if (child == par) continue;
            else if (vis[child]) {
                lowTime[node] = min(lowTime[node], inTime[child]);
            }
            else {
                dfs(child, adj, node);
                lowTime[node] = min(lowTime[child], lowTime[node]);
                if (lowTime[child] > inTime[node]) {
                    if (min(child, node) == c && max(child, node) == d) {
                        ans = true;
                        return;
                    }
                }
            }
        }
    }

public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) {
        // Code here
        inTime.resize(V);
        lowTime.resize(V);
        vis.resize(V);
        timer = 0;
        this->c = min(c, d);
        this->d = max(c, d);
        ans = false;

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs(i, adj, -1);
                if (ans) return 1;
            }
        }

        return 0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int>* adj = new vector<int>[V];
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends