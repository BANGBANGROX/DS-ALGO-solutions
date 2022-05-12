#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int n = nums.size();
		int third = INT_MIN;
		stack<int> s;

		for (int i = n - 1; i >= 0; --i) {
			if (nums[i] < third) return true;
			while (!s.empty() && nums[s.top()] < nums[i]) {
				third = nums[s.top()];
				s.pop();
			}
			s.push(i);
		}

		return false;
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
		if (solution.find132pattern(nums)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}