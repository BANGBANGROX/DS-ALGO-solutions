#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int n = nums.size();
		int currentSum = 0;
		int maxLength = 0;
		unordered_map<int, int> mp;

		for (int i = 0; i < n; ++i) {
			currentSum += (nums[i] == 1) ? 1 : -1;
			if (currentSum == 0) maxLength = max(maxLength, i + 1);
			if (mp.find(currentSum) != mp.end()) {
				maxLength = max(maxLength, i - mp[currentSum]);
			}
			else {
				mp[currentSum] = i;
			}
		}

		return maxLength;
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
		cout << solution.findMaxLength(nums) << endl;
	}

	return 0;
}