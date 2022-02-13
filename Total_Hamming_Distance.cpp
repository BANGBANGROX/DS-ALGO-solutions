#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int ans = 0;
	
		for (int i = 0; i < 32; ++i) {
			int ones = 0;
			int zeroes = 0;
			for (int num : nums) {
				if ((num & (1 << i)) > 0) ++ones;
				else ++zeroes;
			}
			ans += ones * zeroes;
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
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}

		Solution solution;
		cout << solution.totalHammingDistance(nums) << endl;
	}

	return 0;
}