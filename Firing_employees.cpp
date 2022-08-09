//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    vector<bool> prime;

    void sieve() {
        int MAX_N = 2e5 + 5;

        prime = vector<bool>(MAX_N + 1, true);

        prime[0] = prime[1] = false;

        for (int i = 2; i <= MAX_N; ++i) {
            for (int j = 2 * i; j < MAX_N; j += i) {
                prime[j] = false;
            }
        }
    }

    void dfs(int node, vector<vector<int>>& graph, vector<int>& ranks, int level,
        int& ans, vector<bool>& visited) {
        //cout << node + level << endl;

        if (ranks[node - 1] != 0 && prime[node + level]) ++ans;

        visited[node] = true;

        for (int child : graph[node]) {
            if (!visited[child]) {
                dfs(child, graph, ranks, level + 1, ans, visited);
            }
        }
    }

public:
    int firingEmployees(vector<int>& ranks, int n) {
        // code here          
        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1);
        int ans = 0;
        int src = -1;

        sieve();

        for (int i = 0; i < n; ++i) {
            if (ranks[i] == 0) {
                src = i + 1;
                continue;
            }
            graph[ranks[i]].push_back(i + 1);
        }

        dfs(src, graph, ranks, 0, ans, visited);

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends