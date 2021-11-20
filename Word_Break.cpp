#include<bits/stdc++.h>
using namespace std;

bool find(string word, vector<string>& wordDict) {
	for (string w : wordDict) {
		if (w.compare(word) == 0) return true;
	}

	return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
	int n = s.size();
	vector<bool> dp(n + 1); // dp[i]=1 if [0...i-1] can be broken down

	dp[0] = true;

	for (int i = 1; i <= n; ++i) {
		if (find(s.substr(0, i), wordDict)) dp[i] = true;
		if (dp[i]) {
			if (i == n) return true;
			for (int j = i + 1; j <= n; ++j) {
				if (!dp[j] && find(s.substr(i, j - i), wordDict)) dp[j] = true;
				if (j == n && dp[j]) return true;
			}
		}
	}

	return false;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		int n;
		cin >> n;
		vector<string> wordDict(n);
		for (string& x : wordDict) cin >> x;

		if (wordBreak(s, wordDict)) cout << "Break Possible\n";
		else cout << "Break Impossible\n";
	}

	return 0;
}
