#include<bits/stdc++.h>
using namespace std;

int median(vector<vector<int>>& matrix, int r, int c) {
	int minValue = INT_MAX, maxValue = INT_MIN;

	for (int i = 0; i < r; ++i) {
		minValue = min(minValue, matrix[i][0]);
		maxValue = max(maxValue, matrix[i][c - 1]);
	}

	int low = minValue, high = maxValue, required = (r * c + 1) / 2;

	while (low < high) {
		int mid = (low + high) / 2;
		int placed = 0;
		for (int i = 0; i < r; ++i) {
			placed += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
		}
		if (placed < required) low = mid + 1;
		else high = mid;
	}

	return low;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int r, c;
		cin >> r >> c;
		vector<vector<int>> m(r, vector<int>(c));
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> m[i][j];
			}
		}

		cout << median(m, r, c) << endl;
	}

	return 0;
}