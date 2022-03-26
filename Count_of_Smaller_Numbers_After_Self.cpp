// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	void merge(int left, int mid, int right, vector<pair<int, int>>& numsWithIndexes, 
		vector<int>& counts) {
		vector<pair<int, int>> temp(right - left + 1);
		int i = left;
		int j = mid + 1;
		int k = 0;

		while (i <= mid && j <= right) {
			if (numsWithIndexes[i].first <= numsWithIndexes[j].first) {
				temp[k] = numsWithIndexes[j];
				++j;
			}
			else {
				counts[numsWithIndexes[i].second] += (right - j + 1);
				temp[k] = numsWithIndexes[i];
				++i;
			}
			++k;
		}

		while (i <= mid) {
			temp[k] = numsWithIndexes[i];
			++i;
			++k;
		}

		while (j <= right) {
			temp[k] = numsWithIndexes[j];
			++j;
			++k;
		}

		for (int i = left; i <= right; ++i) {
			numsWithIndexes[i] = temp[i - left];
		}
	}

	void mergeSort(int left, int right, vector<pair<int, int>>& numsWithIndexes, vector<int>& counts) {
		if (left < right) {
			int mid = (left + ((right - left) >> 1));

			mergeSort(left, mid, numsWithIndexes, counts);
			mergeSort(mid + 1, right, numsWithIndexes, counts);
			merge(left, mid, right, numsWithIndexes, counts);
		}
	}

public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		vector<pair<int, int>> numsWithIndexes;
		vector<int> ans(n);

		for (int i = 0; i < n; ++i) {
			numsWithIndexes.push_back({ nums[i],i });
		}

		mergeSort(0, n - 1, numsWithIndexes, ans);

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
		vector<int> ans = solution.countSmaller(nums);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}