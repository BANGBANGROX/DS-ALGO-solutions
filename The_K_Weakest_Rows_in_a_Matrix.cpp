// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	int countOnes(vector<int>& binArray) {
		int l = 0;
		int r = binArray.size() - 1;
		int ans = binArray.size();

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (binArray[mid] == 1) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		return ans;
	}

public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		int m = mat.size();
		int n = mat[0].size();
		vector<pair<int, int>> onesCountWithIndex;
		vector<int> ans;

		for (int i = 0; i < m; ++i) {
			int onesCount = countOnes(mat[i]);
			if (onesCount == n) onesCount = 0;
			else ++onesCount;
			onesCountWithIndex.push_back({ onesCount,i });
		}

		sort(onesCountWithIndex.begin(), onesCountWithIndex.end());

		for (int i = 0; i < min((int)onesCountWithIndex.size(), k); ++i) {
			ans.push_back(onesCountWithIndex[i].second);
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
		vector<vector<int>> mat(m, vector<int>(n));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> mat[i][j];
			}
		}

		int k;
		cin >> k;

		Solution solution;
		vector<int> ans = solution.kWeakestRows(mat, k);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}