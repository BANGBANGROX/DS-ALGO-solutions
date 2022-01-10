#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 }, maxTime = 0;
        vector<vector<int>> time(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    time[i][j] = 0;
                    q.push({ i,j });
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int x = curr.first, y = curr.second;
            maxTime = max(maxTime, time[x][y]);
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i], newY = y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && 
                    grid[newX][newY] > 0 && 1 + time[x][y] < time[newX][newY]) {
                    time[newX][newY] = 1 + time[x][y];
                    grid[newX][newY] = 2;
                    q.push({ newX,newY });
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return maxTime;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.orangesRotting(grid) << endl;
    }

    return 0;
}