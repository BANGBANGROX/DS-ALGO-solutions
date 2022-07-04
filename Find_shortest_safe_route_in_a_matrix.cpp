// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int dx[4] = { -1, 0, 0, 1 };
    int dy[4] = { 0, 1, -1, 0 };
    int m;
    int n;
 
public:
    int findShortestPath(vector<vector<int>>& matrix) {
        // code here
        m = matrix.size();
        n = matrix[0].size();
        queue<pair<int, int>> q;
        int length = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0) continue;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == 1) matrix[x][y] = -1;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == -1) matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 1) {
                q.push({ i,0 });
                matrix[i][0] = 0;
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<int, int> currentCell = q.front();
                int x = currentCell.first;
                int y = currentCell.second;
                for (int j = 0; j < 4; ++j) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] == 1) {
                        if (newY == n - 1) return length + 1;
                        q.push({ newX,newY });
                        matrix[newX][newY] = 0;
                    }
                }
            }
            ++length;
        }

        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends