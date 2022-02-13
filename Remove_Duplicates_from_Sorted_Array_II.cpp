#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		int k = 1;
		int cnt = 1;
		int previousNum = nums[0];

		for (int i = 1; i < n; ++i) {
			if (nums[i] == previousNum && cnt < 2) {
				nums[k] = previousNum;
				++k;
				++cnt;
			}
			else if (nums[i] != previousNum) {
				nums[k] = nums[i];
				cnt = 1;
				previousNum = nums[i];
				++k;
			}
		}

		return k;
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
		int k = solution.removeDuplicates(nums);
		cout << k << endl;
		for (int i = 0; i < k; ++i) {
			cout << nums[k] << " ";
		}
		cout << endl;
	}

	return 0;
}