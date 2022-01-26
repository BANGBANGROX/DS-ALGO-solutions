#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, 
		vector<int>& start, int k) {
		int m = grid.size();
		int n = grid[0].size();
		int beginX = start[0];
		int beginY = start[1];
		int lower = pricing[0];
		int upper = pricing[1];
		int dx[4] = { -1,0,1,0 };
		int dy[4] = { 0,1,0,-1 };
		vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
		queue<pair<int, int>> q;
		priority_queue<pair<int, pair<int, pair<int, int>>>, vector< pair<int, pair<int, pair<int, int>>>>> pq;
		vector<vector<int>> ans;

		q.push({ beginX, beginY });
		distance[beginX][beginY] = 0;

		while (!q.empty()) {
			pair<int, int> curr = q.front();
			q.pop();
			int y = curr.second;
			int x = curr.first;
			for (int i = 0; i < 4; ++i) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] > 0) {
					if (distance[newX][newY] > 1 + distance[x][y]) {
						distance[newX][newY] = 1 + distance[x][y];
						q.push({ newX, newY });
					}
				}
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (distance[i][j] == INT_MAX || grid[i][j] == 1 || grid[i][j] < lower || grid[i][j] > upper) continue;
				if (pq.size() < k) pq.push({ distance[i][j],{grid[i][j],{i,j}} });
				else {
				    const auto curr = pq.top();
					if (distance[i][j] <= curr.first) {
						if (distance[i][j] < curr.first) {
							pq.pop();
							pq.push({ distance[i][j],{grid[i][j],{i,j}} });
						}
						else {
							if (grid[i][j] <= curr.second.first) {
								if (grid[i][j] < curr.second.first) {
									pq.pop();
									pq.push({ distance[i][j],{grid[i][j],{i,j}} });
								}
							}
							else {
								if (i <= curr.second.second.first) {
									if (i < curr.second.second.first) {
										pq.pop();
										pq.push({ distance[i][j],{grid[i][j],{i,j}} });
									}
									else {
										if (j < curr.second.second.second) {
											pq.pop();
											pq.push({ distance[i][j],{grid[i][j],{i,j}} });
										}
									}
								}
							}
						}
					}
					
				}
			}
		}

		while (!pq.empty()) {
			const auto curr = pq.top();
			pq.pop();
			ans.push_back({ curr.second.second.first,curr.second.second.second });
		}

		reverse(ans.begin(), ans.end());

		return ans;
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
		vector<int> pricing(2);
		cin >> pricing[0] >> pricing[1];
		vector<int> start(2);
		cin >> start[0] >> start[1];
		int k;
		cin >> k;

		Solution solution;
		vector<vector<int>> ans = solution.highestRankedKItems(grid, pricing, start, k);
		for (const vector<int>& x : ans) {
			cout << x[0] << " " << x[1] << endl;
		}
	}

	return 0;
}