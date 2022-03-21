// https://leetcode.com/problems/divide-array-into-equal-pairs/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool divideArray(vector<int>& nums) {
		int maxNumber = *max_element(nums.begin(), nums.end());
		vector<int> count(maxNumber + 1);

		for (int num : nums) {
			++count[num];
		}

		for (int i = 0; i <= maxNumber; ++i) {
			if ((count[i] & 1) > 0) return false;
		}

		return true;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(2 * n);
		for (int& x : nums) cin >> x;

		Solution solution;
		if (solution.divideArray(nums)) cout << "true\n";
		cout << "false\n";
	}

	return 0;
}