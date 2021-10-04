#include<bits/stdc++.h>
using namespace std;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

bool isValid(int x, int y, int n, int m) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

bool search(vector<vector<char>>& grid, string word, int index, int dir, int x, int y) {
	int size = word.size(), n = grid.size(), m = grid[0].size();

	if (index == size - 1 && grid[x][y] == word[index]) return true;

	if (grid[x][y] != word[index]) return false;

	if (index == 0) {
		bool res = false;
		for (int i = 0; i < 8; ++i) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (isValid(newX, newY, n, m)) {
				res = res | search(grid, word, index + 1, i, newX, newY);
			}
		}
		return res;
	}

	int newX = x + dx[dir], newY = y + dy[dir];

	if (isValid(newX, newY, n, m)) return search(grid, word, index + 1, dir, newX, newY);

	return false;
}

vector<vector<int>>searchWord(vector<vector<char>>& grid, string& word) {
	int n = grid.size(), m = grid[0].size();
	vector<vector<int>> res;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (word[0] == grid[i][j]) {
				if (search(grid, word, 0, 0, i, j)) {
					res.push_back({ i,j });
				}
			}
		}
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		vector<vector<char>> grid(n, vector<char>(m));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cin >> grid[i][j];
		}

		string word;
		cin >> word;

		vector<vector<int>> res = searchWord(grid, word);

		for (vector<int> x : res) cout << x[0] << " " << x[1] << endl;
	}

	return 0;
}
