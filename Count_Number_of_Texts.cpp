#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	vector<int> dp;
	string s;
	int n;
	const int mod = 1e9 + 7;

	int countTextsUtil(int index) {
		if (index >= n) return 1;

		if (dp[index] != -1) return dp[index];

		ll ans = 0;
		int maxCount = (s[index] == '7' || s[index] == '9') ? 4 : 3;

		for (int i = index; i < n && maxCount > 0 && s[i] == s[index]; ++i, --maxCount) {
			ans = (ans + countTextsUtil(i + 1)) % mod;
		}

		return dp[index] = (int)ans;
	}

public:
	int countTexts(string pressedKeys) {
		n = pressedKeys.size();
		s = pressedKeys;
		dp = vector<int>(n, -1);

		return countTextsUtil(0);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string pressedKeys;
		cin >> pressedKeys;

		Solution solution;
		cout << solution.countTexts(pressedKeys) << endl;
	}

	return 0;
}