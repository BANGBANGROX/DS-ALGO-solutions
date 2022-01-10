#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans, inDeg(n);

        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            ++inDeg[v];
        }

        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            edges.push_back({ u,v });
        }

        Solution obj;
        vector<int> ans = obj.findSmallestSetOfVertices(n, edges);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}
