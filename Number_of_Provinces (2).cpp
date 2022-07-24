//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;

        for (int i = 0; i < (int)graph[node].size(); ++i) {
            if (graph[node][i] == 1 && !visited[i]) dfs(i, graph, visited);
        }
    }

public:
    int numProvinces(vector<vector<int>>& graph, int n) {
        // code here
        int ans = 0;
        vector<bool> visited(n);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ans;
                dfs(i, graph, visited);
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
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }


        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
// } Driver Code Ends