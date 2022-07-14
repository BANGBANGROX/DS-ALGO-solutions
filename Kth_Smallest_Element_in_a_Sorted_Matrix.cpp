#include<bits/stdc++.h>
using namespace std;

class Solution {
	int countGreaterUtil(vector<int>& nums, int key) {
		int n = nums.size();
		int l = 0;
		int r = n - 1;
		int ans = n;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (nums[mid] <= key) l = mid + 1;
			else {
				ans = mid;
				r = mid - 1;
			}
		}

		return ans;
	}

	int countLesserUtil(vector<int>& nums, int key) {
		int n = nums.size();
		int l = 0;
		int r = n - 1;
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (nums[mid] >= key) r = mid - 1;
			else {
				ans = mid;
				l = mid + 1;
			}
		}

		return ans;
	}

	int countGreater(vector<vector<int>>& matrix, int key) {
		int ans = 0;
		int n = matrix[0].size();

		for (vector<int>& nums : matrix) {
			ans += (n - countGreaterUtil(nums, key));
		}

		return ans;
	}

	int countLesser(vector<vector<int>>& matrix, int key) {
		int ans = 0;
		int n = matrix[0].size();

		for (vector<int>& nums : matrix) {
			ans += (countLesserUtil(nums, key) + 1);
		}

		return ans;
	}

public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int m = matrix.size();
		int n = matrix[0].size();
		int l = matrix[0][0];
		int r = matrix[m - 1][n - 1];
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			int greater = countGreater(matrix, mid);
			int lesser = countLesser(matrix, mid);
			int equal = (m * n - greater - lesser);
			if (lesser > k) r = mid - 1;
			if (lesser == k || lesser + equal >= k) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		return ans;
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
		int k;
		cin >> k;

		Solution solution;
		cout << solution.kthSmallest(matrix, k) << endl;
	}

	return 0;
}