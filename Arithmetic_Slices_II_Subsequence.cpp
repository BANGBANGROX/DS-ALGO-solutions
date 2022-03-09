#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		int n = nums.size();
		ll ans = 0;
		vector<map<ll, int>> dp(n);

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				ll d = (ll)nums[i] - nums[j];
				int sum = (dp[j].find(d) != dp[j].end()) ? dp[j][d] : 0;
				dp[i][d] += (sum + 1);
				ans += sum;
			}
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
		for (int& x : nums) cin >> x;

		Solution solution;
		cout << solution.numberOfArithmeticSlices(nums) << endl;
	}

	return 0;
}