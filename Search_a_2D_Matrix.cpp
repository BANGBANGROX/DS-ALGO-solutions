#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int r = matrix.size(), c = matrix[0].size();

	for (int i = 0; i < r; ++i) {
		if (target < matrix[i][0] || target > matrix[i][c - 1]) continue;
		if (binary_search(matrix[i].begin(), matrix[i].end(), target)) return true;
	}

	return false;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int r, c;
		cin >> r >> c;

		vector<vector<int>> matrix(r, vector<int>(c));

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) cin >> matrix[i][j];
		}

		int target;
		cin >> target;

		if (searchMatrix(matrix, target)) cout << "FOUND\n";
		else cout << "NOT FOUND\n";
	}

	return 0;
}