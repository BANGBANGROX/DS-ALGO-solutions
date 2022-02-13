// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    int Maximum_Sum(vector<vector<int>>& mat, int n, int k) {
        // Your code goes here
        int ans = INT_MIN;

        // Let's compute the prefix sum matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) mat[i][j] += mat[i][j - 1];
                else if (j == 0) mat[i][j] += mat[i - 1][j];
                else mat[i][j] += (mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1]);
            }
        }

        // Now we consider every square matrix of size k and find its sum
        for (int i = 0; i + k - 1 < n; ++i) {
            for (int j = 0; j + k - 1 < n; ++j) {
                int topLeftRow = i;
                int topLeftCol = j;
                int bottomRightRow = i + k - 1;
                int bottomRightCol = j + k - 1;
                int sum = mat[bottomRightRow][bottomRightCol] - (topLeftRow > 0 ? mat[topLeftRow - 1][bottomRightCol] : 0)
                    - (topLeftCol > 0 ? mat[bottomRightRow][topLeftCol - 1] : 0) +
                    (topLeftCol > 0 && topLeftRow > 0 ? mat[topLeftRow - 1][topLeftCol - 1] : 0);
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> mat[i][j];
            }
        }

        int k; cin >> k;
        Solution obj;
        cout << obj.Maximum_Sum(mat, N, k) << "\n";
    }

    return 0;
}
// } Driver Code Ends