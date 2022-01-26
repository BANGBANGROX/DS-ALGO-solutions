#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int n = s.size();
		int count = 0;
		vector<vector<bool>> dp(n, vector<bool>(n));

		for (int len = 1; len <= n; ++len) {
			for (int i = 0; i <= n - len; ++i) {
				int j = len + i - 1;
				if (len == 1) {
					dp[i][j] = true;
				}
				else if (len == 2) {
					dp[i][j] = (s[i] == s[j]);
				}
				else {
					if (s[i] == s[j]) {
						dp[i][j] = dp[i][j] | dp[i + 1][j - 1];
					}
				}
				if (dp[i][j]) ++count;
			}
		}

		return count;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		cout << solution.countSubstrings(s) << endl;
	}

	return 0;
}