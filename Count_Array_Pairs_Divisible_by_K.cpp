#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
	typedef long long ll;

	int findGCD(int a, int b) {
		if (b == 0) return a;

		return findGCD(b, a % b);
	}

public:
	ll countPairs(vector<int>& nums, int k) {
		ll ans = 0;
		unordered_map<int, int> gcdFrequency;

		for (int& num : nums) {
			int num1GCD = findGCD(num, k);
			for (const pair<int, int>& p : gcdFrequency) {
				if (((ll)num1GCD * p.first) % k == 0) {
					ans += p.second;
				}
			}
			++gcdFrequency[num1GCD];
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
		cout << solution.countPairs(nums, k) << endl;
	}

	return 0;
}