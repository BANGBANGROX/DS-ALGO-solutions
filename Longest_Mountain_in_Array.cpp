#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestMountain(vector<int>& arr) {
		int n = arr.size();
		int maxLength = 0;
		int i = 0;

		while (i < n - 1) {
			int currentLen = 1;
			bool rightSide = false;
			bool leftSide = false;
			// Let's try to find the longest left side of the mountain
			while (i < n - 1 && arr[i] < arr[i + 1]) {
				++i;
				++currentLen;
				leftSide = true;
			}
			if (!leftSide) { // Left side not found so continue
				++i;
				continue;
			}
			// Now we have found the left side, we try to find the longest right side
			while (i < n - 1 && arr[i] > arr[i + 1]) {
				++i;
				++currentLen;
				rightSide = true;
			}
			if (!rightSide) continue; // Right side not found so continue
			maxLength = max(maxLength, currentLen);
		}

		return maxLength;
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
		cout << solution.longestMountain(nums) << endl;
	}

	return 0;
}