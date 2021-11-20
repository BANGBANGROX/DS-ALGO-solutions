// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int minTime(vector<pair<int, int>>& dependency, int duration[], int n, int m) {
        // 	Write your code here
        vector<vector<int>> graph(n);
        vector<int> dp(n), topoSort, inDeg(n);
        queue<int> q;

        for (pair<int, int> edge : dependency) {
            int u = edge.first, v = edge.second;
            graph[u].push_back(v);
            ++inDeg[v];
        }

        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                dp[i] = duration[i];
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for (int child : graph[node]) {
                dp[child] = max(dp[child], duration[child] + dp[node]);
                --inDeg[child];
                if (inDeg[child] == 0) q.push(child);
            }
        }

        int ans = topoSort.size() != n ? -1 : *max_element(dp.begin(), dp.end());

        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int* duration = new int[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({ x, y });
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}  // } Driver Code Ends