#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int mostFrequent(vector<int>& nums, int key) {
		vector<int> count(1005);
		int n = nums.size();
		int maxCount = 0;
		int ans = 0;

		for (int i = 0; i < n - 1; ++i) {
			if (nums[i] == key) {
				++count[nums[i + 1]];
				if (count[nums[i + 1]] > maxCount) {
					ans = nums[i + 1];
					maxCount = count[nums[i + 1]];
				}
			}
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
		int key;
		cin >> key;

		Solution solution;
		cout << solution.mostFrequent(nums, key) << endl;
	}

	return 0;
}