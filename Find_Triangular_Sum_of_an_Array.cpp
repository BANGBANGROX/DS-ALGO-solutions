#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int triangularSum(vector<int>& nums) {
		if (nums.size() == 1) return nums[0] % 10;

		vector<int> newNums;

		for (int i = 1; i < nums.size(); ++i) {
			newNums.push_back((nums[i] + nums[i - 1]) % 10);
		}

		return triangularSum(newNums);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}

		Solution solution;
		cout << solution.triangularSum(nums) << endl;
	}

	return 0;
}