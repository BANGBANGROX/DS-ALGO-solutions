#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n);

		sort(nums.begin(), nums.end());

		int i = 1;
		int j = n - 1;

		while (i < n) {
			ans[i] = nums[j];
			i += 2;
			--j;
		}

		i = 0;

		while (i < n) {
			ans[i] = nums[j];
			i += 2;
			--j;
		}

		for (int k = 0; k < n; ++k) {
			nums[k] = ans[k];
		}
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
		solution.wiggleSort(nums);
		for (int& x : nums) cout << x << " ";
		cout << endl;
	}

	return 0;
}