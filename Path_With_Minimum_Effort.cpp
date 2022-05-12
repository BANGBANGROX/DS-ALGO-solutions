#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumEffortPath(vector<vector<int>>& heights) {
		int m = heights.size();
		int n = heights[0].size();
		int dx[4] = { -1, 0, 0, 1 };
		int dy[4] = { 0, 1, -1, 0 };
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		vector<vector<bool>> visited(m, vector<bool>(n));
		vector<vector<int>> best(m, vector<int>(n, INT_MAX));

		pq.push({ 0,{0,0} });
		best[0][0] = 0;

		while (!pq.empty()) {
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			int effort = pq.top().first;
			pq.pop();
			if (visited[x][y]) continue;
			if (x == m - 1 && y == n - 1) return effort;
			visited[x][y] = true;
			for (int i = 0; i < 4; ++i) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newY >= 0 && newX < m && newY < n && !visited[newX][newY]) {
					int newEffort = max(effort, abs(heights[x][y] - heights[newX][newY]));
					if (newEffort < best[newX][newY]) {
						best[newX][newY] = newEffort;
						pq.push({ newEffort,{newX,newY} });
					}
				}
			}
		}

		return 0;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> heights(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> heights[i][j];
			}
		}

		Solution solution;
		cout << solution.minimumEffortPath(heights) << endl;
	}

	return 0;
}