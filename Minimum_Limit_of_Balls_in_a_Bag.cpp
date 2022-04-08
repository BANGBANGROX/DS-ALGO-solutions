#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool check(vector<int>& nums, int maxOperations, int value) {
		int operations = 0;

		for (int num : nums) {
			if (num <= value) break;
			if (num % value == 0) operations += (num / value - 1);
			else operations += num / value;
			if (operations > maxOperations) return false;
		}

		return true;
	}

public:
	int minimumSize(vector<int>& nums, int maxOperations) {
		sort(nums.begin(), nums.end(), greater<int>());

		int l = 1;
		int r = nums[0];
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (check(nums, maxOperations, mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
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
		int maxOperations;
		cin >> maxOperations;

		Solution solution;
		cout << solution.minimumSize(nums, maxOperations) << endl;
	}

	return 0;
}