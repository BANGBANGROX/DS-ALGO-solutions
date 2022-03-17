// { Driver Code Starts
// Initial Template for C++

// https://practice.geeksforgeeks.org/problems/height-using-parent-array4103/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int height;

    void dfs(int node, vector<vector<int>>& tree, int parent, int level) {
        height = max(height, level);

        for (int child : tree[node]) {
            if (child != parent) dfs(child, tree, parent, level + 1);
        }
    }

public:
    int findHeight(int n, int parents[]) {
        // code here
        vector<vector<int>> graph(n);
        int rootNode = -1;

        for (int i = 0; i < n; ++i) {
            if (parents[i] == -1) {
                rootNode = i;
                continue;
            }
            graph[parents[i]].push_back(i);
        }

        height = 0;

        dfs(rootNode, graph, -1, 1);

        return height;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int* arr = new int[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.findHeight(N, arr) << "\n";
    }
    return 0;
}  // } Driver Code Ends