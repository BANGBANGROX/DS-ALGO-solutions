#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> inDeg(n), ans;
        queue<int> q;

        for (vector<int> e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            ++inDeg[u];
            ++inDeg[v];
        }

        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 1) {
                q.push(i);
                --inDeg[i];
            }
        }

        while (!q.empty()) {
            ans.clear();
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for (int node : graph[curr]) {
                    --inDeg[node];
                    if (inDeg[node] == 1) q.push(node);
                }
            }
        }

        if (n == 1) return { 0 };

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edges.push_back({ u,v });
        }

        Solution obj;
        vector<int> ans = obj.findMinHeightTrees(n, edges);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}