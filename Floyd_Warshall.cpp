#include<bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>& matrix) {
	int n = matrix.size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == -1) matrix[i][j] = INT_MAX;
		}
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == INT_MAX) matrix[i][j] = -1;
		}
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		vector<vector<int>> matrix(n, vector<int>(n));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cin >> matrix[i][j];
		}

		shortest_distance(matrix);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
