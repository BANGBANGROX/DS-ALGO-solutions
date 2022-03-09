// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<int>> computeBeforeMatrix(int n, int m, vector<vector<int>> after) {
        // Code here
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j > 0; --j) {
                after[i][j] -= after[i][j - 1];
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j > 0; --j) {
                after[i][j] -= after[i - 1][j];
            }
        }

        return after;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> after(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> after[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> before = obj.computeBeforeMatrix(N, M, after);
        for (int i = 0; i < before.size(); i++) {
            for (int j = 0; j < before[i].size(); j++) {
                cout << before[i][j] << ' ';
            }
            cout << endl;
        }
    }
}  // } Driver Code Ends