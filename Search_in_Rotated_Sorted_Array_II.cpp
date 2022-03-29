#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool isBinarySearchHelpful(vector<int>& nums, int start, int key) {
		return nums[start] != key;
	}

	bool existsInFirst(vector<int>& nums, int start, int key) {
		return nums[start] <= key;
	}

public:
	bool search(vector<int>& nums, int target) {
		int n = nums.size();
		int start = 0;
		int end = n - 1;

		while (start <= end) {
			int mid = (start + ((end - start) >> 1));
			if (nums[mid] == target) return true;
			if (!isBinarySearchHelpful(nums, start, nums[mid])) {
				++start;
				continue;
			}
			bool pivotPosition = existsInFirst(nums, start, nums[mid]);
			bool targetPosition = existsInFirst(nums, start, target);
			if (pivotPosition ^ targetPosition) {
				if (pivotPosition) start = mid + 1;
				else end = mid - 1;
			}
			else {
				if (nums[mid] < target) start = mid + 1;
				else end = mid - 1;
			}
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
		int target;
		cin >> target;

		Solution solution;
		if (solution.search(nums, target)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}