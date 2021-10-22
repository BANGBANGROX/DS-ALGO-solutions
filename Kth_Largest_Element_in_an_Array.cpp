#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < nums.size(); ++i) {
		if (pq.size() < k) pq.push(nums[i]);
		else {
			int x = pq.top();
			if (x < nums[i]) {
				pq.pop();
				pq.push(nums[i]);
			}
		}
	}

	return pq.top();
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << findKthLargest(nums, k) << endl;
	}

	return 0;
}