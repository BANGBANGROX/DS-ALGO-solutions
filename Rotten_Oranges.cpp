#include<bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m) {
	return x > -1 && y > -1 && x < n && y < m;
}

bool isDelim(pair<int, int> x) {
	return x == make_pair(-1, -1);
}

int orangesRotting(vector<vector<int>>& grid) {
	queue<pair<int, int>> q;
	int n = grid.size(), m = grid[0].size(), ans = 0;
	int dx[] = { 0,-1,1,0 };
	int dy[] = { -1,0,0,1 };

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}

	q.push({ -1,-1 });

	while (!q.empty()) {
		bool flag = false;
		while (!isDelim(q.front())) {
			pair<int, int> top = q.front();
			int x = top.first, y = top.second;
			for (int i = 0; i < 4; ++i) {
				if (isValid(x + dx[i], y + dy[i], n, m) && grid[x + dx[i]][y + dy[i]] == 1) {
					grid[x + dx[i]][y + dy[i]] = 2;
					if (!flag) {
						++ans;
						flag = true;
					}
					q.push({ x + dx[i],y + dy[i] });
				}
			}
			q.pop();
		}
		q.pop();
		if (!q.empty()) {
			q.push({ -1,-1 });
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 1) return -1;
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(n));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> grid[i][j];
			}
		}

		cout << orangesRotting(grid) << endl;
	}

	return 0;
}