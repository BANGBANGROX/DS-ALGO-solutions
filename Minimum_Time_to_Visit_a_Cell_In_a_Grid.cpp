#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int m = (int) grid.size();
        int n = (int) grid[0].size();
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, 1, -1, 0};
        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        pq.push({0, 0, 0});

        while (!pq.empty()) {
            vector<int> cell = pq.top();
            pq.pop();
            int x = cell[1];
            int y = cell[2];
            if (visited[x][y]) continue;
            int t = cell[0];
            if (x == m - 1 && y == n - 1) return t;
            visited[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newY >= 0 && newX < m && newY < n && !visited[newX][newY]) {
                    int waitTime = (grid[newX][newY] - t) % 2 == 0;
                    pq.push({max(grid[newX][newY] + waitTime, t + 1), newX, newY});
                }
            }
        }

        return -1;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
         int m, n;
         cin >> m >> n;
         vector<vector<int>> grid(m, vector<int>(n));
         for (vector<int>&x: grid) {
             for (int &y: x) {
                 cin >> y;
             }
         }

         Solution solution;
         cout << solution.minimumTime(grid) << endl;
    }

    return 0;
}
