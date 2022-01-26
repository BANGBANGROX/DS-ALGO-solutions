#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();

		for (int lastNonZero = 0, i = 0; i < n; ++i) {
			if (nums[i] != 0) {
				swap(nums[lastNonZero], nums[i]);
				++lastNonZero;
			}
		}
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
		solution.moveZeroes(nums);
		for (int x : nums) cout << x << " ";
		cout << endl;
	}

	return 0;
}