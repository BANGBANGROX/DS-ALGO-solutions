#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countPairs(vector<int>& nums, int k) {
		int ans = 0;
		int n = nums.size();

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (nums[i] == nums[j] && (i * j) % k == 0) ++ans;
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		cin >> k;

		Solution solution;
		cout << solution.countPairs(nums, k) << endl;
	}

	return 0;
}