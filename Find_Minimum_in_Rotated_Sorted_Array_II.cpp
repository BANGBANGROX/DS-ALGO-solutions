#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int l = 0;
		int r = n - 1;

		while (l < r) {
			int mid = (l + ((r - l) >> 1));
			if (nums[mid] == nums[r]) {
				--r;
			}
			else if (nums[mid] < nums[r]) r = mid;
			else l = mid + 1;
		}

		return nums[l];
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
		cout << solution.findMin(nums) << endl;
	}

	return 0;
}