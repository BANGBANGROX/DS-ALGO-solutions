// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector <int> maximumDistance(vector<vector<int>>& edges, int n, int e, int src) {
        // code here
        vector<vector<vector<int>>> graph(n);
        vector<int> ans(n, INT_MIN);
        queue<int> q;

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({ v,w });
        }

        q.push(src);
        ans[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (vector<int>& childNode : graph[node]) {
                int child = childNode[0];
                int weight = childNode[1];
                if (ans[child] < ans[node] + weight) {
                    ans[child] = ans[node] + weight;
                    q.push(child);
                }
            }
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--)
    {

        int v, e;
        cin >> v >> e;

        int src;
        cin >> src;
        vector<vector<int>> edges(e, vector<int>(3));
        for (auto& j : edges)
            cin >> j[0] >> j[1] >> j[2];

        Solution s;
        vector <int> ans = s.maximumDistance(edges, v, e, src);
        for (auto j : ans)
        {
            if (j == INT_MIN)
                cout << "INF ";
            else
                cout << j << " ";
        }
        cout << endl;
    }
    return 0;

}  // } Driver Code Ends