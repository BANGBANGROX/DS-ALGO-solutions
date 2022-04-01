// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int node, vector<int> graph[], vector<int>& levels, int parent, int level) {
        ++levels[level];

        for (int child : graph[node]) {
            if (child != parent) dfs(child, graph, levels, node, level + 1);
        }
    }

public:
    int countOfNodes(vector<int> graph[], int n) {
        // code here
        vector<int> levels(n);
        int ans = 0;
        int evenSum = 0;
        int oddSum = 0;

        dfs(1, graph, levels, -1, 0);

        for (int i = 0; i < n; ++i) {
            ans += levels[i] * (levels[i] - 1) / 2;
        }

        for (int i = n - 1; i >= 0; --i) {
            if ((i & 1) > 0) {
                ans += levels[i] * oddSum;
                oddSum += levels[i];
            }
            else {
                ans += levels[i] * evenSum;
                evenSum += levels[i];
            }
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
        vector<int>* graph = new vector<int>[n + 1];
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout << ob.countOfNodes(graph, n) << endl;
    }
    return 0;
}  // } Driver Code Ends