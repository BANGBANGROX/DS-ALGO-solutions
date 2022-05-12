// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool eulerPath(int n, vector<vector<int>> graph) {
        // code here
        int evenDegree = 0;
        int oddDegree = 0;

        for (int i = 0; i < n; ++i) {
            int count = accumulate(graph[i].begin(), graph[i].end(), 0);
            if ((count & 1) > 0) ++oddDegree;
            else ++evenDegree;
        }

        return oddDegree == 0 || oddDegree == 2;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> graph[i][j];

        Solution ob;
        cout << ob.eulerPath(N, graph) << "\n";
    }
    return 0;
}  // } Driver Code Ends