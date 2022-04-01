#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDeletion(vector<int>& nums) {
		int n = nums.size();
		int deletions = 0;
		bool flip = false;
		int i = 0;

		while (i < n) {
			if (flip) {
				if ((i & 1) > 0) {
					if (i + 1 < n && nums[i] == nums[i + 1]) {
						++deletions;
						flip = false;
					}
				}
			}
			else {
				if ((i & 1) == 0) {
					if (i + 1 < n && nums[i] == nums[i + 1]) {
						++deletions;
						flip = true;
					}
				}
			}
			++i;
		}
		
		if ((n - deletions) % 2 == 1) ++deletions;

		return deletions;
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
		cout << solution.minDeletion(nums) << endl;
	}

	return 0;
}