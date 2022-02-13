#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		bool isCol = false;

		for (int i = 0; i < m; ++i) {
			if (matrix[i][0] == 0) isCol = true;
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
			}
		}

		if (matrix[0][0] == 0) {
			for (int j = 0; j < n; ++j) {
				matrix[0][j] = 0;
			}
		}

		if (isCol) {
			for (int i = 0; i < m; ++i) {
				matrix[i][0] = 0;
			}
		}
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> matrix(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> matrix[i][j];
			}
		}

		Solution solution;
		solution.setZeroes(matrix);

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}