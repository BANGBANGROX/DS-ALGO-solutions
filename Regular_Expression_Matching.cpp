#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
	vector<vector<int>> dp;

	bool isMatchUtil(int i, int j, string s, string p) {
		int m = s.size();
		int n = p.size();

		if (i >= m && j >= n) return true;

		if (j >= n) return false;

		if (dp[i][j] != -1) return dp[i][j];

		bool match = (i < m && (s[i] == p[j] || p[j] == '.'));

		if (j + 1 < n && p[j + 1] == '*') {
			return dp[i][j] = isMatchUtil(i, j + 2, s, p) || (match && isMatchUtil(i + 1, j, s, p));
		}

		if (match) return dp[i][j] = isMatchUtil(i + 1, j + 1, s, p);

		return dp[i][j] = false;
	}

public:
	bool isMatch(string s, string p) {
		dp = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));

		return isMatchUtil(0, 0, s, p);
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