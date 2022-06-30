#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int n = nums.size();
		int median = nums[n / 2];
		int ans = 0;

		for (int i = 0; i < n; ++i) {
			ans += abs(median - nums[i]);
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
		cout << solution.minMoves2(nums) << endl;
	}

	return 0;
}