#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<int> findGreatestSubsequence(vector<int>& nums, int len) {
		vector<int> ans;
		int n = nums.size();

		for (int i = 0; i < n; ++i) {
			while (!ans.empty() && ((int)ans.size() + n - i - 1) >= len && nums[i] > ans.back()) {
				ans.pop_back();
			}
			if (ans.size() < len) ans.push_back(nums[i]);
		}

		return ans;
	}

	bool isGreater(vector<int>& nums1, vector<int>& nums2, int i, int j) {
		int n = nums1.size();
		int m = nums2.size();

		while (i < n || j < m) {
			if (i >= n) return false;
			if (j >= m) return true;
			if (nums1[i] < nums2[j]) return false;
			if (nums1[i] > nums2[j]) return true;
			++i;
			++j;
		}

		return true;
	}

	vector<int> mergeSubsequences(vector<int>& nums1, vector<int>& nums2) {
		int i = 0;
		int j = 0;
		int m = nums1.size();
		int n = nums2.size();
		vector<int> ans;

		while (i < m || j < n) {
			if (i >= m) {
				ans.push_back(nums2[j]);
				++j;
			}
			else if (j >= n) {
				ans.push_back(nums1[i]);
				++i;
			}
			else if (nums1[i] > nums2[j]) {
				ans.push_back(nums1[i]);
				++i;
			}
			else if (nums1[i] < nums2[j]) {
				ans.push_back(nums2[j]);
				++j;
			}
			else {
				if (isGreater(nums1, nums2, i, j)) {
					ans.push_back(nums1[i]);
					++i;
				}
				else {
					ans.push_back(nums2[j]);
					++j;
				}
			}
		}

		return ans;
	}

public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> ans;
		int m = nums1.size();
		int n = nums2.size();

		for (int len1 = 0; len1 <= k; ++len1) {
			int len2 = k - len1;
			if (len1 > m || len2 > n) continue;
			vector<int> max1 = findGreatestSubsequence(nums1, len1);
			vector<int> max2 = findGreatestSubsequence(nums2, len2);
			vector<int> merged = mergeSubsequences(max1, max2);
			if (merged > ans) {
				ans = merged;
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n, k;
		cin >> m;
		vector<int> nums1(m);
		for (int& x : nums1) cin >> x;
		cin >> n;
		vector<int> nums2(n);
		for (int& x : nums2) cin >> x;
		cin >> k;

		Solution solution;
		vector<int> ans = solution.maxNumber(nums1, nums2, k);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}