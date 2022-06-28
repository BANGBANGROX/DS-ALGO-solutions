// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<int>> rotateMatrix(int m, int n, vector<vector<int>> matrix) {
        // code here
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top < bottom && left < right) {
            int temp = matrix[top + 1][left];
            // Going left to right
            for (int i = left; i <= right; ++i) {
                swap(temp, matrix[top][i]);
            }
            ++top;
            // Going top to bottom
            for (int i = top; i <= bottom; ++i) {
                swap(matrix[i][right], temp);
            }
            --right;
            // Going right to left
            for (int i = right; i >= left; --i) {
                swap(matrix[bottom][i], temp);
            }
            --bottom;
            // Going bottom to top
            for (int i = bottom; i >= top; --i) {
                swap(matrix[i][left], temp);
            }
            ++left;
        }

        return matrix;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends