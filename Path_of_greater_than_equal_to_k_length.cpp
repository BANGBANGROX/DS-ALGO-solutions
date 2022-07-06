// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
    vector<vector<vector<int>>> graph;
    vector<bool> visited;
    bool ans = false;
    int target;

    void dfs(int node, int length) {
        if (length >= target) {
            ans = true;
            return;
        }

        visited[node] = true;

        for (vector<int>& childNode : graph[node]) {
            int child = childNode[0];
            int weight = childNode[1];
            if (!visited[child]) {
                dfs(child, length + weight);
                if (ans) return;
            }
        }

        visited[node] = false;
    }

public:
    bool pathMoreThanK(int n, int e, int k, int* a) {
        //  Code Here
        graph = vector<vector<vector<int>>>(n);
        visited = vector<bool>(n);
        target = k;
        int len = 3 * e;

        for (int i = 0; i < len; i += 3) {
            int u = a[i];
            int v = a[i + 1];
            int w = a[i + 2];
            graph[u].push_back({ v,w });
            graph[v].push_back({ u,w });
        }
        
        dfs(0, 0);

        return ans;
    }
};




// { Driver Code Starts.


int main() {
    //code
    int t; cin >> t;
    while (t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int* a = new int[3 * E + 1];
        for (int i = 0; i < 3 * E; i++) {
            cin >> a[i];
        }

        Solution obj;
        if (obj.pathMoreThanK(V, E, K, a)) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }

    }
    return 0;
}  // } Driver Code Ends