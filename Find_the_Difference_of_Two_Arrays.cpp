#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, bool> presentIn1;
		unordered_map<int, bool> presentIn2;
		vector<vector<int>> ans(2);

		for (int num : nums1) {
			presentIn1[num] = true;
		}

		for (int num : nums2) {
			presentIn2[num] = true;
		}

		for (const pair<int, bool>& num : presentIn1) {
			if (presentIn2.find(num.first) == presentIn2.end()) {
				ans[0].push_back(num.first);
			}
		}

		for (const pair<int, bool>& num : presentIn2) {
			if (presentIn1.find(num.first) == presentIn1.end()) {
				ans[1].push_back(num.first);
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m;
		vector<int> nums1(m);
		for (int& x : nums1) cin >> x;
		cin >> n;
		vector<int> nums2(n);
		for (int& x : nums2) cin >> x;

		Solution solution;
		vector<vector<int>> ans = solution.findDifference(nums1, nums2);
		for (const vector<int>& x : ans) {
			for (const int& y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}