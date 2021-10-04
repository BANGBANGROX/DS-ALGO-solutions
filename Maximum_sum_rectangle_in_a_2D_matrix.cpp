#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int>& a, int* start, int* finish, int n) {
	int maxSum = INT_MIN, sum = 0, maxElement = INT_MIN, index = -1, localStart = 0;
	*finish = -1;

	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum < 0) {
			sum = 0;
			localStart = i + 1;
		}
		else if (sum > maxSum) {
			maxSum = sum;
			*start = localStart;
			*finish = i;
		}
		if (a[i] > maxElement) {
			maxElement = a[i];
			index = i;
		}
	}

	if (*finish == -1) {
		maxSum = maxElement;
		*start = *finish = index;
	}

	return maxSum;
}

int maximumSumRectangle(int row, int col, vector<vector<int>>& M) {
	int maxSum = INT_MIN, leftBoundary = -1, rightBoundary = -1, topBoundary = -1, bottomBoundary = -1;

	for (int left = 0; left < col; ++left) {
		vector<int> temp(row, 0);
		for (int right = left; right < col; ++right) {
			for (int i = 0; i < row; ++i) {
				temp[i] += M[i][right];
			}
			int top = -1, bottom = -1;
			int currSum = kadane(temp, &top, &bottom, row);
			if (currSum > maxSum) {
				maxSum = currSum;
				leftBoundary = left;
				rightBoundary = right;
				topBoundary = top;
				bottomBoundary = bottom;
			}
		}
	}

	return maxSum;
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

	cout << maximumSumRectangle(n, m, M) << endl;

	return 0;
}