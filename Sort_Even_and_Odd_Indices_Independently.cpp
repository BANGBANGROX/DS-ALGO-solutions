#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> sortEvenOdd(vector<int>& nums) {
		vector<int> evenNums;
		vector<int> oddNums;
		int n = nums.size();
		int oddIndex = 0;
		int evenIndex = 0;

		for (int i = 0; i < n; ++i) {
			if ((i & 1) > 0) {
				oddNums.push_back(nums[i]);
			}
			else {
				evenNums.push_back(nums[i]);
			}
		}

		sort(evenNums.begin(), evenNums.end());
		sort(oddNums.begin(), oddNums.end(), greater<int>());

		for (int i = 0; i < n; ++i) {
			if ((i & 1) > 0) {
				nums[i] = oddNums[oddIndex];
				++oddIndex;
			}
			else {
				nums[i] = evenNums[evenIndex];
				++evenIndex;
			}
		}

		return nums;
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
		vector<int> ans = solution.sortEvenOdd(nums);
		for (int i = 0; i < n; ++i) cout << ans[i] << " ";
		cout << endl;
	}

	return 0;
}