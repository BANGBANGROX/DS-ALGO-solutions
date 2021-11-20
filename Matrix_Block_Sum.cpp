#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
	int n = mat.size(), m = mat[0].size();
	vector<vector<int>> ans(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 0) mat[i][j] += mat[i - 1][j];
			if (j > 0) mat[i][j] += mat[i][j - 1];
			if (i > 0 && j > 0) mat[i][j] -= mat[i - 1][j - 1];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int rowSt = max(0, i - k), rowEnd = min(n - 1, i + k), colSt = max(0, j - k), 
				colEnd = min(m - 1, j + k);
			ans[i][j] = mat[rowEnd][colEnd];
			if (rowSt > 0) ans[i][j] -= mat[rowSt - 1][colEnd];
			if (colSt > 0) ans[i][j] -= mat[rowEnd][colSt - 1];
			if (rowSt > 0 && colSt > 0) ans[i][j] += mat[rowSt - 1][colSt - 1];
			
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m, k;
		cin >> n >> m;
		vector<vector<int>> mat(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cin >> mat[i][j];
		}
		cin >> k;

		vector<vector<int>> ans = matrixBlockSum(mat, k);
		for (vector<int>x : ans) {
			for (int y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}