#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();

		k %= n;

		int i = 0;
		int j = k;
		vector<int> ans(n);

		while (j < n) {
			ans[j] = nums[i];
			++j;
			++i;
		}

		j = 0;

		while (j < k) {
			ans[j] = nums[i];
			++j;
			++i;
		}

		for (int i = 0; i < n; ++i) {
			nums[i] = ans[i];
		}
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		cin >> k;

		Solution solution;
		solution.rotate(nums, k);
		for (int i = 0; i < n; ++i) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}

	return 0;
}