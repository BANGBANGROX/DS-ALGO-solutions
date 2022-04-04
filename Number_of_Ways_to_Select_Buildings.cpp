#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	ll numberOfWays(string s) {
		int zeroesCountBefore = 0;
		int onesCountBefore = 0;
		int zeroesCountAfter = 0;
		int onesCountAfter = 0;
		ll ans = 0;
		int n = s.size();

		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') ++zeroesCountBefore;
			else ++onesCountBefore;
		}

		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				ans += ((ll)zeroesCountAfter * zeroesCountBefore);
				++onesCountAfter;
				--onesCountBefore;
			}
			else {
				ans += ((ll)onesCountAfter * onesCountBefore);
				++zeroesCountAfter;
				--zeroesCountBefore;
			}
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
		cout << solution.numberOfWays(s) << endl;
	}

	return 0;
}