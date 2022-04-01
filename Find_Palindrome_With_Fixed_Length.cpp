#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	ll reverse(ll num, int skip) {
		ll ans = 0;

		for (ll n = skip == 0 ? num / 10 : num; n > 0; n /= 10) {
			ans = ans * 10 + n % 10;
		}

		return ans;
	}

public:
	vector<ll> kthPalindrome(vector<int>& queries, int intLength) {
		vector<ll> ans;
		ll start = pow(10, (intLength + 1) / 2 - 1);
		ll end = pow(10, (intLength + 1) / 2) - 1;
		ll mul = pow(10, intLength / 2);

		for (int q : queries) {
			ans.push_back(start + q - 1 > end ? -1 : 
				(start + q - 1) * mul + reverse(start + q - 1, intLength % 2));
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
		vector<int> queries(n);
		for (int& x : queries) cin >> x;
		int intLength;
		cin >> intLength;

		Solution solution;
		vector<long long> ans = solution.kthPalindrome(queries, intLength);
		for (long long& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}