#include<bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool isValid(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& vis) {
	int m = board.size(), n = board[0].size();

	return x > -1 && x < m && y > -1 && y < n && board[x][y] == 'O' && vis[x][y] == false;
}

void solve(vector<vector<char>>& board) {
	int m = board.size(), n = board[0].size();
	queue<pair<int, int>> q;
	vector<vector<bool>> vis(m, vector<bool>(n));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'O' && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) 
				q.push({ i,j });
		}
	}

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		int x = curr.first, y = curr.second;
		vis[x][y] = 1;
		for (int i = 0; i < 4; ++i) {
			int newX = x + dx[i], newY = y + dy[i];
			if (isValid(newX, newY, board, vis)) {
				q.push({ newX,newY });
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
		}
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<char>> board(m, vector<char>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> board[i][j];
			}
		}

		solve(board);

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}