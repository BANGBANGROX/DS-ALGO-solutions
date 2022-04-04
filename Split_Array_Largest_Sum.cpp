#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool check(vector<int>& nums, int sum, int m) {
		int currentSum = 0;
		int splits = 1;

		for (int num : nums) {
			if (currentSum + num <= sum) {
				currentSum += num;
			}
			else {
				++splits;
				currentSum = num;
				if (splits > m) return false;
			}
		}

		return true;
	}

public:
	int splitArray(vector<int>& nums, int m) {
		int l = *max_element(nums.begin(), nums.end());
		int r = accumulate(nums.begin(), nums.end(), 0);
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (check(nums, mid, m)) {
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
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		int m;
		cin >> m;

		Solution solution;
		cout << solution.splitArray(nums, m) << endl;
	}

	return 0;
}