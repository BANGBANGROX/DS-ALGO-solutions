#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int currentSum = 0;
		int n = nums.size();
		unordered_map<int, int> mp;

		for (int i = 0; i < n; ++i) {
			currentSum += nums[i];
			currentSum %= k;
			if (currentSum == 0 && i > 0) return true;
			if (mp.find(currentSum) != mp.end()) {
				int len = i - mp[currentSum];
				if (len >= 2) return true;
			}
			else mp[currentSum] = i;
		}

		return false;
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
		int k;
		cin >> k;

		Solution solution;
		if (solution.checkSubarraySum(nums, k)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}