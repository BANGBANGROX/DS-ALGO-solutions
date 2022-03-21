// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int halveArray(vector<int>& nums) {
		int n = nums.size();
		priority_queue<double> pq;
		double target = 0;
		double reduced = 0;
		int ans = 0;

		for (int i = 0; i < n; ++i) {
			pq.push((double)nums[i]);
			target += (double)nums[i] / 2;
		}

		while (reduced < target) {
			double val = pq.top();
			pq.pop();
			reduced += val / 2;
			pq.push(val / 2);
			++ans;
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
		for (int& x : nums) cin >> x;

		Solution solution;
		cout << solution.halveArray(nums) << endl;
	}

	return 0;
}