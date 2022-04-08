#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool check(vector<int>& nums, int divisor, int threshold) {
		int ans = 0;

		for (int num : nums) {
			ans += ceil(double(num) / divisor);
			if (ans > threshold) return false;
		}

		return true;
	}

public:
	int smallestDivisor(vector<int>& nums, int threshold) {
		int l = 1;
		int r = 1e9;
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (check(nums, mid, threshold)) {
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
		int threshold;
		cin >> threshold;

		Solution solution;
		cout << solution.smallestDivisor(nums, threshold) << endl;
	}

	return 0;
}