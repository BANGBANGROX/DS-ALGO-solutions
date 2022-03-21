#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	const int mod = 1e9 + 7;

	ll binExp(ll a, ll b) {
		ll res = 1;

		while (b > 0) {
			if ((b & 1) > 0) {
				res = ((res % mod) * (a % mod)) % mod;
				--b;
			}
			a = ((a % mod) * (a % mod)) % mod;
			b /= 2;
		}

		return res;
	}

public:
	int makeStringSorted(string s) {
		int n = s.size();
		ll ans = 0;
		int total = 0;
		vector<ll> factorial(n + 1);
		vector<ll> invFactorial(n + 1);
		vector<int> count(26);

		factorial[0] = 1;
		invFactorial[0] = binExp(1, (ll)mod - 2);

		for (int i = 1; i <= n; ++i) {
			factorial[i] = (i * factorial[i - 1]) % mod;
			invFactorial[i] = binExp(factorial[i], (ll)mod - 2);
		}

		for (int i = n - 1; i >= 0; --i) {
			int idx = s[i] - 'a';
			++count[idx];
			for (int i = 0; i < idx; ++i) {
				if (count[i] > 0) {
					--count[i];
					ll totalPermutations = factorial[total];
					for (int j = 0; j < 26; ++j) {
						if (count[j] > 1) {
							totalPermutations = (totalPermutations * invFactorial[count[j]]) % mod;
						}
					}
					ans = (ans + totalPermutations) % mod;
					++count[i];
				}
			}
			++total;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		cout << solution.makeStringSorted(s) << endl;
	}

	return 0;
}