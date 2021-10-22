#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size();
	int m = nums2.size();

	if (n > m) return findMedianSortedArrays(nums2, nums1);

	int start = 0, end = n, midInMerged = (n + m + 1) / 2;

	while (start <= end) {
		int mid = (start + end) / 2;
		int leftASize = mid;
		int leftBSize = midInMerged - mid;
		int leftA = (leftASize > 0) ? nums1[leftASize - 1] : INT_MIN;
		int leftB = (leftBSize > 0) ? nums2[leftBSize - 1] : INT_MIN;
		int rightA = (leftASize < n) ? nums1[leftASize] : INT_MAX;
		int rightB = (leftBSize < m) ? nums2[leftBSize] : INT_MAX;
		if (leftA <= rightB && leftB <= rightA) {
			if ((m + n) % 2 == 0) {
				return ((double)max(leftA, leftB) + min(rightA, rightB)) / 2.0;
			}
			return max(leftA, leftB);
		}
		if (leftA > rightB) end = mid - 1;
		else start = mid + 1;
	}

	return 0;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int> nums1(n), nums2(m);
		for (int& x : nums1) cin >> x;
		for (int& y : nums2) cin >> y;

		double median = findMedianSortedArrays(nums1, nums2);

		cout << median << endl;
	}

	return 0;
}