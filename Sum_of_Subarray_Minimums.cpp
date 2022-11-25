#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int sumSubarrayMins(vector<int>& nums) {
		const int MOD = (int)1e9 + 7;
		int n = (int)nums.size();
		long ans = 0;
		stack<int> st;

		for (int i = 0; i <= n; ++i) {
			while (!st.empty() && (i == n || nums[st.top()] >= nums[i])) {
				int mid = st.top();
				st.pop();
				int left = st.empty() ? -1 : st.top();
				long count = (((long)mid - left) * ((long)i - mid)) % MOD;
				ans = (ans + (count * nums[mid]) % MOD) % MOD;
			}
			st.push(i);
		}

		return (int)ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) {
			cin >> x;
		}

		Solution solution;
		cout << solution.sumSubarrayMins(nums) << endl;
	}

	return 0;
}