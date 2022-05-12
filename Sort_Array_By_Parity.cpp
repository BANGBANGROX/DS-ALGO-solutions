#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		stable_sort(nums.begin(), nums.end(), [](int a, int b) {
			int parityOfA = a % 2;
			int parityOfB = b % 2;

			if (parityOfA == parityOfB) return a < b;

			if (parityOfA == 0) return true;

			return false;
			});

		return nums;
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
		vector<int> nums = solution.sortArrayByParity(nums);
		for (int& x : nums) cout << x << " ";
		cout << endl;
	}

	return 0;
}