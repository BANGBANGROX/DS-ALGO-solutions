#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix(n, vector<int>(n));
	int num = 1, r1 = 0, c1 = 0, r2 = n - 1, c2 = n - 1;

	while (r1 < r2) {
		// fill row r1
		for (int i = c1; i <= c2; ++i) {
			matrix[r1][i] = num;
			++num;
		}
		++r1;

		// fill col c2
		for (int i = r1; i <= r2; ++i) {
			matrix[i][c2] = num;
			++num;
		}
		--c2;

		// fill row r2
		for (int i = c2; i >= c1; --i) {
			matrix[r2][i] = num;
			++num;
		}
		--r2;

		// fill col c1
		for (int i = r2; i >= r1; --i) {
			matrix[i][c1] = num;
			++num;
		}
		++c1;
	}
	if (r1 == r2) matrix[r1][r2] = num;

	return matrix;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<vector<int>> matrix = generateMatrix(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cout << matrix[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
