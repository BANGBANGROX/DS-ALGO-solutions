#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumDeviation(vector<int>& nums) {
		int maxNum = INT_MIN;
		int minNum = INT_MAX;
		int ans = 0;
		priority_queue<int> pq;

		for (int num : nums) {
			if ((num & 1) > 0) {
				num *= 2;
			}
			pq.push(num);
			maxNum = max(maxNum, num);
			minNum = min(minNum, num);
		}

		ans = maxNum - minNum;

		while (pq.top() % 2 == 0) {
			int top = pq.top();
			pq.pop();
			ans = min(ans, top - minNum);
			top /= 2;
			minNum = min(minNum, top);
			pq.push(top);
		}

		ans = min(ans, pq.top() - minNum);

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
		cout << solution.minimumDeviation(nums) << endl;
	}

	return 0;
}