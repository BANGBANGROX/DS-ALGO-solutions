// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int timer = 0;
    bool ans = false;
    int componentSize = 0;

    void dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& low, vector<int>& disc,
        vector<bool>&visited) {
        visited[node] = true;
        low[node] = disc[node] = ++timer;
        ++componentSize;

        int children = 0;
        
        for (int child : graph[node]) {
            if (!visited[child]) {
                dfs(child, node, graph, low, disc, visited);
                low[node] = min(low[node], low[child]);
                if (parent != -1 && low[child] >= disc[node]) ans = true;
                ++children;
            }
            else if (child != parent) low[node] = min(low[node], disc[child]);
        }

        if (parent == -1 && children > 1) ans = true;
    }

public:
    int biGraph(int arr[], int n, int e) {
        // code here
        vector<vector<int>> graph(n);

        for (int i = 0; i < 2 * e - 1; i += 2) {
            int u = arr[i];
            int v = arr[i + 1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> low(n);
        vector<int> disc(n);
        vector<bool> visited(n);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, -1, graph, low, disc, visited);
                if (ans || componentSize == 1) return 0;
                timer = 0;
                componentSize = 0;
            }
        }

        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;

        int* arr = new int[2 * e];
        for (int i = 0; i < 2 * e; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.biGraph(arr, n, e) << endl;
    }
    return 0;
}  // } Driver Code Ends