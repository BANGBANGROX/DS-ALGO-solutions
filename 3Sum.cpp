#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> ans;
	map<vector<int>, bool> done;

	sort(begin(nums), end(nums));

	for (int i = 0; i < n - 2; ++i) {
		if (nums[i] > 0) break;
		int l = i + 1, r = n - 1, sum = -1 * nums[i];
		vector<int> curr;
		curr.push_back(nums[i]);
		while (l < r) {
			int currSum = nums[l] + nums[r];
			if (currSum == sum) {
				curr.push_back(nums[l]);
				curr.push_back(nums[r]);
				if (done.find(curr) == done.end()) ans.push_back(curr);
				done[curr] = true;
				curr.pop_back();
				curr.pop_back();
				++l;
				--r;
			}
			else if (currSum > sum) --r;
			else ++l;
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		vector<vector<int>> ans = threeSum(nums);
		for (vector<int>x : ans) {
			for (int y : x) cout << y << " ";
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
