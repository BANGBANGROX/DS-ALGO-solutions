#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();

		for (int i = 0; i < n; ++i) {
			while (nums[i] != i + 1) {
				if (nums[i] <= 0 || nums[i] > n || nums[nums[i] - 1] == nums[i]) break;
				swap(nums[nums[i] - 1], nums[i]);
			}
		}

		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) return i + 1;
		}

		return n + 1;
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
		cout << solution.firstMissingPositive(nums) << endl;
	}

	return 0;
}