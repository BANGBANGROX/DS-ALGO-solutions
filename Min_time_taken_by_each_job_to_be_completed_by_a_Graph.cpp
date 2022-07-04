// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> ans;

    void dfs(int node) {
        visited[node] = true;
        int maxTime = 0;

        for (int child : graph[node]) {
            if (!visited[child]) dfs(child);
            maxTime = max(maxTime, ans[child]);
        }

        ans[node] += maxTime;
    }

public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, int m) {
        // code here
        graph = vector<vector<int>>(n);
        visited = vector<bool>(n);
        ans = vector<int>(n, 1);

        for (vector<int>& edge : edges) {
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) dfs(i);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<vector<int>> edges(m, vector<int>(2));
        for (int i = 0; i < m; i++)
            cin >> edges[i][0] >> edges[i][1];
        Solution s;
        vector<int> ans = s.minimumTime(n, edges, m);
        for (auto j : ans)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends