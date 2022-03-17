#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	int findGCD(ll a, ll b) {
		if (b == 0) return a;

		return findGCD(b, a % b);
	}
public:
	vector<int> replaceNonCoprimes(vector<int>& nums) {
		vector<int> ans;

		for (int& num : nums) {
			while (true) {
				int lastValue = (ans.empty() ? 1 : ans.back());
				int gcd = findGCD(num, lastValue);
				if (gcd == 1) break;
				ans.pop_back();
				num = (ll)num * lastValue / gcd;
			}
			ans.push_back(num);
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
		vector<int> ans = solution.replaceNonCoprimes(nums);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}