#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		int n = nums.size();
		int ptr1 = 1;
		int ptr2 = 0;
		vector<int> positive, negative;

		for (int num : nums) {
			if (num > 0) positive.push_back(num);
			else negative.push_back(num);
		}

		nums[0] = positive[0];

		for (int i = 1; i < n; ++i) {
			if (ptr1 > ptr2) {
				nums[i] = negative[ptr2];
				++ptr2;
			}
			else {
				nums[i] = positive[ptr1];
				++ptr1;
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
		vector<int> ans = solution.rearrangeArray(nums);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}