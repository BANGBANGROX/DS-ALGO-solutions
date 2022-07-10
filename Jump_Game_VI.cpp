#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxResult(vector<int>& nums, int k) {
		int n = nums.size();
		priority_queue<vector<int>> pq;

		pq.push({ nums[0], 0 });

		for (int i = 1; i < n; ++i) {
			while (!pq.empty() && (i - pq.top()[1]) > k) pq.pop();
			if (pq.empty()) pq.push({ nums[i],i });
			else pq.push({ nums[i] + pq.top()[0],i });
		}

		while (!pq.empty()) {
			if (pq.top()[1] == n - 1) return pq.top()[0];
			pq.pop();
		}

		return -1;
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
		int k;
		cin >> k;

		Solution solution;
		cout << solution.maxResult(nums, k) << endl;
	}

	return 0;
}