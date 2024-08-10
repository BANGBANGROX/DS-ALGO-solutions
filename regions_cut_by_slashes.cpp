#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<bool>> graph;
    
    void dfs(int x, int y) {
        int m = graph.size();
        int n = graph[0].size();

        if (x < 0 || x >= m || y < 0 || y >= n || graph[x][y]) {
            return;
        }

        graph[x][y] = true;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (vector<int> &direction : directions) {
            int new_x = x + direction[0];
            int new_y = y + direction[1];
            dfs(new_x, new_y);
        }
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int answer = 0;
        graph = vector<vector<bool>>(m * 3, vector<bool>(n * 3, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    graph[i * 3][j * 3] = graph[i * 3 + 1][j * 3 + 1] = graph[i * 3 + 2][j * 3 + 2] = true;
                }
                if (grid[i][j] == '/') {
                    graph[i * 3 + 2][j * 3] = graph[i * 3][j * 3 + 2] = graph[i * 3 + 1][j * 3 + 1] = true; 
                }
            }
        }

        for (int i = 0; i < m * 3; ++i) {
            for (int j = 0; j < n * 3; ++j) {
                if (!graph[i][j]) {
                    ++answer;
                    dfs(i, j);
                }
            }
        }

        return answer;
    }
};