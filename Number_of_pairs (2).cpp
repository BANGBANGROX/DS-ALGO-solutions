// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    typedef long long int ll;

    vector<vector<int>> graph;
    vector<bool> visited;
    int componentSize;

    void dfs(int node) {
        visited[node] = true;

        for (int child : graph[node]) {
            if (!visited[child]) dfs(child);
        }

        ++componentSize;
    }

public:
    ll numberOfPairs(vector<vector<int>>& pairs, int p, int n) {
        // code here
        graph = vector<vector<int>>(n);
        visited = vector<bool>(n);
        ll ans = (ll)n * ((ll)n - 1) / 2;

        for (vector<int>& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                componentSize = 0;
                dfs(i);
                ans -= (ll)componentSize * ((ll)componentSize - 1) / 2;
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
        int n, p;
        cin >> n >> p;
        vector<vector<int>> pairs(p, vector<int>(2));
        for (auto& i : pairs)
            for (auto& j : i)
                cin >> j;
        Solution a;
        cout << a.numberOfPairs(pairs, p, n) << endl;
    }
}  // } Driver Code Ends