// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
		vector<int> ans;
		int n = nums.size();

		for (int i = 0; i < n; ++i) {
			for (int j = max(0, i - k); j <= min(i + k, n - 1); ++j) {
				if (nums[j] == key) {
					ans.push_back(i);
					break;
				}
			}
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
		int k, key;
		cin >> key >> k;

		Solution solution;
		vector<int> ans = solution.findKDistantIndices(nums, key, k);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}