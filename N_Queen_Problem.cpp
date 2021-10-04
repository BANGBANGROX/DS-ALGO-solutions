#include<bits/stdc++.h>
using namespace std;

vector<bool> ld, rd, cl;

void solveNQueen(vector<vector<int>>& ans, vector<vector<bool>>& board, int col) {
	int n = board.size();
	if (col >= n) {
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j]) {
					v.push_back(j + 1);
				}
			}
		}
		ans.push_back(v);
		return;
	}
    
	for (int i = 0; i < n; ++i) {
		if (ld[i - col + n - 1] == 0 && rd[i + col] == 0 && cl[i] == 0 && board[i][col] == 0) {
			ld[i - col + n - 1] = rd[i + col] = cl[i] = board[i][col] = 1;
			solveNQueen(ans, board, col + 1);
			ld[i - col + n - 1] = rd[i + col] = cl[i] = board[i][col] = 0;
		}
	}
}

vector<vector<int>> nQueen(int n) {
	vector<vector<bool>> board(n, vector<bool>(n));
	ld.resize(2 * n);
	rd.resize(2 * n);
	cl.resize(n);
    vector<vector<int>> ans;
	
	solveNQueen(ans, board, 0);
	sort(ans.begin(), ans.end());

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> ans = nQueen(n);

		for (int i = 0; i < ans.size(); ++i) {
			for (int x : ans[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
