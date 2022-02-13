#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

public:
	ll minimumDifference(vector<int>& nums) {
		int n = nums.size() / 3;
		int size = 3 * n;
		ll ans = LONG_MAX;
		ll leftSum = 0;
		ll rightSum = 0;
		priority_queue<int> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;
		vector<ll> prefix(size);

		for (int i = size - 1; i >= n; --i) {
			rightSum += nums[i];
			minHeap.push(nums[i]);
			if (minHeap.size() > n) {
				rightSum -= minHeap.top();
				minHeap.pop();
			}
			if (minHeap.size() == n) prefix[i] = rightSum;
		}

		for (int i = 0; i < size - n; ++i) {
			leftSum += nums[i];
			maxHeap.push(nums[i]);
			if (maxHeap.size() > n) {
				leftSum -= maxHeap.top();
				maxHeap.pop();
			}
			if (maxHeap.size() == n) {
				ans = min(ans, leftSum - prefix[i + 1]);
			}
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
		cout << solution.minimumDifference(nums) << endl;
	}

	return 0;
}