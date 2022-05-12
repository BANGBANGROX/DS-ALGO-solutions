// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
    vector<vector<int>> graph;
    vector<bool> visited;

    void dfs(int node) {
        visited[node] = true;

        for (int child : graph[node]) {
            if (!visited[child]) {
                dfs(child);
            }
        }
    }

public:
    int captainAmerica(int n, int m, vector<vector<int>>& edges) {
        // Code Here
        graph = vector<vector<int>>(n + 1);
        visited = vector<bool>(n + 1);
        queue<int> q;
        int mother = -1;
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[v].push_back(u);
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                mother = i;
                dfs(i);
            }
        }

        fill(visited.begin(), visited.end(), false);
        
        assert(mother != -1);
        dfs(mother);

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) return 0;
            graph[i].clear();
            visited[i] = false;
        }

        for (int i = 0; i < m;++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
        }
            
        q.push(mother);
        visited[mother] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ++ans;
            for (int child : graph[node]) {
                if (!visited[child]) {
                    visited[child] = true;
                    q.push(child);
                }
            }
        }

        return ans;
    }
};

// { Driver Code Starts.


int main() {
    int t; cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            v[i].push_back(a);
            v[i].push_back(b);
        }

        Solution obj;
        cout << obj.captainAmerica(n, m, v) << endl;
    }

}  // } Driver Code Ends