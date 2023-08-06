#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

    vector<vector<int>> closestThiefDistance(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        queue<vector<int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({ i, j });
                    result[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            vector<int> cell = q.front();
            int x = cell[0];
            int y = cell[1];
            q.pop();
            for (vector<int>& direction : directions) {
                int newX = x + direction[0];
                int newY = y + direction[1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    result[newX][newY] > result[x][y] + 1) {
                    result[newX][newY] = result[x][y] + 1;
                    q.push({ newX, newY });
                }
            }
        }

        return result;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

        vector<vector<int>> distances = closestThiefDistance(grid);
        priority_queue<vector<int>> pq;

        pq.push({ distances[0][0], 0, 0 });

        while (pq.top()[1] < m - 1 || pq.top()[2] < n - 1) {
            vector<int> cell = pq.top();
            pq.pop();
            int dis = cell[0];
            int x = cell[1];
            int y = cell[2];
            for (vector<int>& direction : directions) {
                int newX = x + direction[0];
                int newY = y + direction[1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    distances[newX][newY] != -1) {
                    pq.push({ min(distances[newX][newY],dis), newX, newY });
                    distances[newX][newY] = -1;
                }
            }
        }

        return pq.top()[0];
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for (vector<int>& x : grid) {
            for (int& y : x) {
                cin >> y;
            }
        }

        Solution solution;
        cout << solution.maximumSafenessFactor(grid) << endl;
    }

    return 0;
}