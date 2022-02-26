#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> dp;

	int isMatchUtil(int i, int j, string& s, string& p) {
		if (i == s.size() && j == p.size()) return 1;

		if (i == s.size()) {
			for (int k = j; k < p.size(); ++k) {
				if (p[k] != '*') return 0;
			}

			return 1;
		}

		if (j == p.size()) return 0;

		if (dp[i][j] != -1) return dp[i][j];

		if (p[j] == '*') {
			return dp[i][j] = isMatchUtil(i + 1, j, s, p) || isMatchUtil(i + 1, j + 1, s, p)
				|| isMatchUtil(i, j + 1, s, p);
		}

		return dp[i][j] = (p[j] == '?' || p[j] == s[i]) && isMatchUtil(i + 1, j + 1, s, p);
	}

public:
	bool isMatch(string s, string p) {
		dp = vector<vector<int>>(s.size(), vector<int>(p.size(), -1));

		int ans = isMatchUtil(0, 0, s, p);

		if (ans > 0) return true;

		return false;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s, p;
		cin >> s >> p;

		Solution solution;
		if (solution.isMatch(s, p)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}