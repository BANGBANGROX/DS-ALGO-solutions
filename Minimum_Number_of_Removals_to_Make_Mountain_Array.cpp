#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumMountainRemovals(vector<int>& nums) {
		int n = nums.size();
		int ans = INT_MAX;
		vector<int> start(n, 1);
		vector<int> end(n, 1);

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j]) {
					start[i] = max(start[i], start[j] + 1);
				}
			}
		}

		for (int i = n - 2; i >= 0; --i) {
			for (int j = n - 1; j > i; --j) {
				if (nums[i] > nums[j]) {
					end[i] = max(end[i], end[j] + 1);
				}
			}
		}

		for (int i = 1; i < n; ++i) {
			if (start[i] == 1 || end[i] == 1) continue;
			ans = min(ans, n - start[i] - end[i] + 1);
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
		cout << solution.minimumMountainRemovals(nums) << endl;
	}

	return 0;
}