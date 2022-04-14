#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<int> prefixSum;
	int n;

	int splitMid(int start, int key) {
		int l = start;
		int r = n - 2;
		int ans = -1;
		
		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			int sum = prefixSum[mid] - (start == 0 ? 0 : prefixSum[start - 1]);
			if (sum >= key) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		return ans;
	}

	int splitRight(int start, int key) {
		int l = start;
		int r = n - 2;
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			int sum = prefixSum[mid] - (start == 0 ? 0 : prefixSum[start - 1]);
			if (sum <= key) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		return ans;
	}

public:
	int waysToSplit(vector<int>& nums) {
		n = nums.size();
		prefixSum = vector<int>(nums.begin(), nums.end());
		int ans = 0;
		const int mod = 1e9 + 7;

		for (int i = 1; i < n; ++i) {
			prefixSum[i] += prefixSum[i - 1];
		}

		for (int i = 0; i < n - 2; ++i) {
			int leftSum = prefixSum[i];
			int remainingSum = prefixSum[n - 1] - leftSum;
			if (prefixSum[n - 1] < leftSum * 3) break;
			int l = splitMid(i + 1, leftSum);
			int r = splitRight(i + 1, remainingSum / 2);
			ans = (ans + (r - l + 1)) % mod;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		Solution solution;
		cout << solution.waysToSplit(nums) << endl;
	}

	return 0;
}