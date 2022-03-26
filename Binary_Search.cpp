#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (nums[mid] == target) return mid;
			if (nums[mid] < target) l = mid + 1;
			else r = mid - 1;
		}

		return -1;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, target;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		cin >> target;

		Solution solution;
		cout << solution.search(nums, target) << endl;
	}

	return 0;
}