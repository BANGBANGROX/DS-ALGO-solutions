#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> mostCompetitive(vector<int>& nums, int k) {
		vector<int> ans;
		int n = nums.size();

		for (int i = 0; i < n; ++i) {
			while (!ans.empty() && (ans.size() + n - i - 1) >= k && nums[i] < ans.back()) {
				ans.pop_back();
			}
			if (ans.size() < k) ans.push_back(nums[i]);
		}

		return ans;
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
		vector<int> ans = solution.mostCompetitive(nums, k);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}