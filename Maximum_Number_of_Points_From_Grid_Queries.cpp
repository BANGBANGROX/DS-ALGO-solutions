#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<bool>> visited;
	vector<vector<int>> grid;
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	int m;
	int n;

	int bfs(int key) {
		int result = 0;
		int dx[] = { -1, 0, 0, 1 };
		int dy[] = { 0, 1, -1, 0 };

		while (!pq.empty()) {
			vector<int> cell = pq.top();
			int value = cell[0];
			if (value >= key) break;
			pq.pop();
			++result;
			int x = cell[1];
			int y = cell[2];
			for (int i = 0; i < 4; ++i) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newY >= 0 && newX < m && newY < n && !visited[newX][newY]) {
					pq.push({ grid[newX][newY],newX,newY });
					visited[newX][newY] = true;
				}
			}
		}

		return result;
	}

public:
	vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
		this->grid = grid;
		m = (int)grid.size();
		n = (int)grid[0].size();
		int q = (int)queries.size();
		visited = vector<vector<bool>>(m, vector<bool>(n));
		vector<int> ans(q);
		vector<int> prefix(q);
		vector<vector<int>> sortedQueries;

		for (int i = 0; i < q; ++i) {
			sortedQueries.push_back({ queries[i],i });
		}

		sort(sortedQueries.begin(), sortedQueries.end());
		pq.push({ grid[0][0],0,0 });
		visited[0][0] = true;

		for (int i = 0; i < q; ++i) {
			vector<int> query = sortedQueries[i];
			int key = query[0];
			int index = query[1];
			int result = bfs(key);
			if (i == 0) {
				prefix[i] = result;
			}
			else {
				prefix[i] = prefix[i - 1] + result;
			}
			ans[index] = prefix[i];
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
		vector<vector<int>> grid(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}
		int q;
		cin >> q;
		vector<int> queries(q);
		for (int& x : queries) {
			cin >> x;
		}

		Solution solution;
		vector<int> ans = solution.maxPoints(grid, queries);
		for (int x : ans) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}