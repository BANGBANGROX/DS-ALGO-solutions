#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> edges;
    vector<bool> visited;
    unordered_map<int,int> distance;
    int ans;

    void dfs(int node) {
        visited[node] = true;
        int child = edges[node];

        if (child == -1) return;

        if (!visited[child]) {
            distance[child] = distance[node] + 1;
            dfs(child);
        }
        else if (visited[child] && distance.find(child) != distance.end()) {
            ans = max(ans, distance[node] - distance[child] + 1);
        }
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = (int) edges.size();
        this->edges = edges;
        visited = vector<bool>(n);
        ans = -1;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                distance.clear();
                distance[i] = 1;
                dfs(i);
            }
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> edges(n);
        for (int &x: edges) cin >> x;
        
        Solution solution;
        cout << solution.longestCycle(edges) << endl;
    }

    return 0;
}
