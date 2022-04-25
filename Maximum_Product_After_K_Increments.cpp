#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

public:
	int maximumProduct(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
		ll ans = 1;
		const int mod = 1e9 + 7;
		
		while (k > 0) {
			int top = pq.top();
			pq.pop();
			pq.push(top + 1);
			--k;
		}

		while (!pq.empty()) {
			ans = (ans * pq.top()) % mod;
			pq.pop();
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
		int k;
		cin >> k;

		Solution solution;
		cout << solution.maximumProduct(nums, k) << endl;
	}

	return 0;
}