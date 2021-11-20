#include<bits/stdc++.h>
using namespace std;

int getMaxLen(vector<int>& nums) {
	nums.push_back(0);

	int n = nums.size(), l = -1, r = -1, negCount = 0, maxLen = 0, lastZero = 0;

	for (int i = 0; i < n; ++i) {
		if (nums[i] < 0) {
			++negCount;
			if (l == -1) l = i;
			r = i;
		}
		if (nums[i] == 0) {
			if (negCount % 2 == 0) maxLen = max(maxLen, i - lastZero);
			else maxLen = max(maxLen, max(i - l - 1, r - lastZero));
			lastZero = i + 1;
			negCount = 0;
			l = -1;
			r = -1;
		}
	}

	return maxLen;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << getMaxLen(nums) << endl;
	}

	return 0;
}