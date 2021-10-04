#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int snakesAndLadders(vector<vector<int>>& board) {
	int n = board.size(), target = n * n;
	unordered_map<int, int> moves;
	queue<int> q;

	q.push(1);

	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i) {
			int newSquare = top + i;
			if (newSquare > target) break;
			int row = (newSquare - 1) / n;
			int col = (row % 2 == 0) ? (newSquare - 1) % n : (n - 1 - (newSquare - 1) % n);
			if (board[n - 1 - row][col] != -1) {
				newSquare = board[n - 1 - row][col];
			}
			if (moves.find(newSquare) == moves.end()) {
				moves[newSquare] = moves[top] + 1;
				if (newSquare == target) return moves[newSquare];
				q.push(newSquare);
			}
		}
	}
 	
	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> board(n, vector<int>(n));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cin >> board[i][j];
		}

		cout << snakesAndLadders(board) << endl;
	}

	return 0;
}