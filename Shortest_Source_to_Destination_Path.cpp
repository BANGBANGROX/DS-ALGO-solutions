// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int shortestDistance(int m, int n, vector<vector<int>>& matrix, int targetX, int targetY) {
        // code here
        if (matrix[0][0] == 0 || matrix[targetX][targetY] == 0) return -1;

        if (targetX == 0 && targetY == 0) return 0;

        int ans = 1;
        queue<pair<int, int>> q;
        int dx[4] = { -1, 0, 0, 1 };
        int dy[4] = { 0, 1, -1, 0 };

        q.push({ 0,0 });

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];
                    if (newX == targetX && newY == targetY) return ans;
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] == 1) {
                        q.push({ newX,newY });
                        matrix[newX][newY] = 0;
                    }
                }
            }
            ++ans;
        }

        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends