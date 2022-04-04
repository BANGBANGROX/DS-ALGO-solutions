#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	vector<int> zFunction(string s) {
		int n = s.size();
		vector<int> z(n);

		for (int i = 1, l = 0, r = 0; i < n; ++i) {
			if (i <= r) {
				z[i] = min(r - i + 1, z[i - l]);
			}
			while (i + z[i] < n && s[z[i]] == s[z[i] + i]) {
				++z[i];
			}
			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}

		return z;
	}

public:
	ll sumScores(string s) {
		int n = s.size();
		ll ans = n;
		vector<int> z = zFunction(s);

		for (int i = 1; i < n; ++i) {
			ans += (ll)z[i];
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
		cout << solution.sumScores(s) << endl;
	}

	return 0;
}