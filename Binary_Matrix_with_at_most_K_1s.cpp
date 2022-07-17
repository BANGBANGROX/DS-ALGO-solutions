//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    bool check(int x, int y, int len, int k, vector<vector<int>>& matrix) {
        int firstRow = x - len;
        int firstCol = y - len;
        int lastRow = x + len;
        int lastCol = y + len;

        int sum = matrix[lastRow][lastCol] - (firstRow > 0 ? matrix[firstRow - 1][lastCol] : 0) -
            (firstCol > 0 ? matrix[lastRow][firstCol - 1] : 0) + (firstRow > 0 && firstCol > 0 ?
                matrix[firstRow - 1][firstCol - 1] : 0);

        return sum <= k;
    }

public:
    vector<int> largestSquare(vector<vector<int>>& matrix, int m, int n, int k,
        int q, int x[], int y[]) {
        // code here
        vector<int> res;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0) matrix[i][j] += matrix[i][j - 1];
                else if (j == 0) matrix[i][j] += matrix[i - 1][j];
                else matrix[i][j] += (matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1]);
            }
        }

        for (int i = 0; i < q; ++i) {
            int maxLength = min({ x[i],y[i],m - x[i] - 1,n - y[i] - 1 });
            int l = 0;
            int r = maxLength;
            int ans = 0;
            while (l <= r) {
                int mid = (l + ((r - l) >> 1));
                if (check(x[i], y[i], mid, k, matrix)) {
                    ans = 2 * mid + 1;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            res.push_back(ans);
        }

        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C, K, Q, x;
        cin >> R >> C;
        vector<vector<int>> M;

        for (int a = 0; a < R; a++)
        {
            vector<int> temp;
            for (int b = 0; b < C; b++)
            {
                cin >> x;
                temp.push_back(x);
            }
            M.push_back(temp);
        }

        cin >> K >> Q;

        int* q_i = new int[Q], * q_j = new int[Q];

        for (int i = 0; i < Q; i++)
            cin >> q_i[i];
        for (int i = 0; i < Q; i++)
            cin >> q_j[i];

        Solution ob;
        vector<int> res = ob.largestSquare(M, R, C, K, Q, q_i, q_j);

        for (int i = 0; i < Q; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends