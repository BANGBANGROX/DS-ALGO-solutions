#include<bits/stdc++.h>
using namespace std;

void sumZero(vector<int>& a, int* start, int* finish, int n) {
	map<int, int> pref;
	int sum = 0, maxLen = 0;

	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (a[i] == 0 && maxLen == 0) {
			maxLen = 1;
			*start = *finish = i;
		}
		if (sum == 0) {
			if (maxLen < i + 1) {
				maxLen = i + 1;
				*start = 0;
				*finish = i;
			}
		}
		if (pref.find(sum) != pref.end()) {
			if (maxLen < i - pref[sum]) {
				maxLen = i - pref[sum];
				*start = pref[sum] + 1;
				*finish = i;
			}
		}
		else {
			pref[sum] = i;
		}
	}
}

int findRectMatrix(int row, int col, vector<vector<int>>& M) {
	int maxLen = 0, finalTop = -1, finalBottom = -1, finalLeft = -1, finalRight = -1;

	for (int left = 0; left < col; ++left) {
		vector<int> temp(row);
		for (int right = left; right < col; ++right) {
			for (int i = 0; i < row; ++i) {
				temp[i] += M[i][right];
			}
			int top = -1, bottom = -1;
			sumZero(temp, &top, &bottom, row);
			if (top == -1) continue;
			int currLen = (right - left + 1) * (bottom - top + 1);
			if (currLen > maxLen) {
				maxLen = currLen;
				finalLeft = left;
				finalRight = right;
				finalBottom = bottom;
				finalTop = top;
			}
		}
	}
	if (M[0][0] == 0 && maxLen == 0) maxLen = 1;

	return maxLen;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> M(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> M[i][j];
		}
	}

	cout << findRectMatrix(n, m, M) << endl;

	return 0;
}