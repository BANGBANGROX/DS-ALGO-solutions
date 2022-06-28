// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxOnes(vector<vector<int>>& matrix, int m, int n) {
        // your code here
        int ans = -1;
        int maxOnes = 0;

        for (int i = 0; i < m; ++i) {
            int idx = upper_bound(matrix[i].begin(), matrix[i].end(), 0) - matrix[i].begin();
            if (maxOnes < (n - idx)) {
                ans = i;
                maxOnes = n - idx;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector <vector <int>> arr(n, vector <int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends