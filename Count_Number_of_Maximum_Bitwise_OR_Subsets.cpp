#include<bits/stdc++.h>
using namespace std;

int countMaxOrSubsets(vector<int>& nums) {
	int n = nums.size(), maxOr = 0, cnt = 0;

	for (int mask = 1; mask < (1 << n); ++mask) {
		int currOr = 0;
		for (int i = 0; i < n; ++i) {
			if ((1 << i) & mask) {
				currOr |= nums[i];
			}
		}
		maxOr = max(maxOr, currOr);
	}

	for (int mask = 1; mask < (1 << n); ++mask) {
		int currOr = 0;
		for (int i = 0; i < n; ++i) {
			if ((1 << i) & mask) {
				currOr |= nums[i];
			}
		}
		if (maxOr == currOr) ++cnt;
	}


	return cnt;
}

int main() {
	int T;
	cin >> T;
	
	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);

		for (int& x : nums) cin >> x;

		cout << countMaxOrSubsets(nums) << endl;
	}

	return 0;
}