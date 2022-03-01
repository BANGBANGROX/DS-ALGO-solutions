#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		int i = 0;
		int n = nums.size();

		if (n == 1) return { to_string(nums[0]) };

		while (i < n) {
			int a = nums[i];
			while (i < n && nums[i + 1] == nums[i] + 1) {
				++i;
			}
		    if (nums[i] == a) ans.push_back(to_string(a));
			else ans.push_back(to_string(a) + "->" + to_string(nums[i]));
			++i;
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

		Solution solution;
		vector<string> ans = solution.summaryRanges(nums);
		for (string& x : ans) cout << x << endl;
	}

	return 0;
}