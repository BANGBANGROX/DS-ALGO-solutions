#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        int dx[4] = { 1,-1,0,0 };
        int dy[4] = { 0,0,-1,1 };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({ i,j });
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int x = curr.first, y = curr.second;
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i], newY = y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && ans[newX][newY] > ans[x][y] + 1) {
                    ans[newX][newY] = ans[x][y] + 1;
                    q.push({ newX,newY });
                }
            }
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        vector<vector<int>> ans = obj.updateMatrix(mat);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}