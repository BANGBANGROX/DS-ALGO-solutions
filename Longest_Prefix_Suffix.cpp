#include<bits/stdc++.h>
using namespace std;

int lps(string s) {
	int n = s.size();
	vector<int> dp(n);
	int i = 1, len = 0;

	while (i < n) {
		if (s[i] == s[len]) {
			++len;
			dp[i] = len;
			++i;
		}
		else {
			if (len == 0) {
				dp[i] = 0;
				++i;
			}
			else len = dp[len - 1];
		}
	}

	return dp[n - 1];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << lps(s) << endl;
	}

	return 0;
}