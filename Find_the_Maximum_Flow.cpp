// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int bfs(int n, int source, int sink, vector<vector<int>>& graph, vector<int>& parent) {
        vector<bool> visited(n + 1);
        queue<int> q;
        int bottleneckFlow = INT_MAX;

        q.push(source);
        visited[source] = true;
        parent[source] = -1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 1; i <= n; ++i) {
                if (!visited[i] && graph[node][i] != 0) {
                    visited[i] = true;
                    parent[i] = node;
                    bottleneckFlow = min(bottleneckFlow, graph[node][i]);
                    if (i == sink) return bottleneckFlow;
                    q.push(i);
                }
            }
        }

        return 0;
    }

    int fordFulkersonAlgorithm(int n, int source, int sink, vector<vector<int>>& graph) {
        vector<int> parent(n + 1, -1);
        int maxFlow = 0;
        int currentFlow = 0;

        while ((currentFlow = bfs(n, source, sink, graph, parent)) != 0) {
            maxFlow += currentFlow;
            int node = sink;
            while (node != source) {
                int par = parent[node];
                graph[par][node] -= currentFlow;
                graph[node][par] += currentFlow;
                node = par;
            }
        }

        return maxFlow;
    }

public:
    int solve(int n, int m, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> graph(n + 1, vector<int>(n + 1));

        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int flow = edge[2];
            graph[u][v] += flow;
            graph[v][u] += flow;
        }

        return fordFulkersonAlgorithm(n, 1, n, graph);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i, j, N, M, u, v, w;
        int res;
        scanf_s("%d %d", &N, &M);
        vector<vector<int>> Edges;
        for (i = 0; i < M; i++)
        {
            scanf_s("%d %d %d", &u, &v, &w);
            Edges.push_back({ u,v,w });
        }
        Solution obj;
        res = obj.solve(N, M, Edges);
        cout << res << endl;
    }
    return 0;
}  // } Driver Code Ends