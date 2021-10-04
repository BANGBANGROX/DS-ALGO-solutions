#include<bits/stdc++.h>
using namespace std;

int palindromicPartition(string s) {
	int n = s.size();
	vector<vector<bool>> isPalindrome(n, vector<bool>(n)); // table to check if [i...j] is a palindrome
	vector<int> dp(n, INT_MAX); // dp[i] is the answer for [0...i]
	for (int i = 0; i < n; ++i) {
		isPalindrome[i][i] = 1;
	}

	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i <= n - len; ++i) {
			int j = i + len - 1;
			if (len == 2) {
				isPalindrome[i][j] = (s[i] == s[j]);
			}
			else {
				isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (isPalindrome[0][i]) { // if [0...i] is a palindrome then no need to cut 
			dp[i] = 0;   
		}
		else {  // if not
			for (int j = 0; j < i; ++j) {
				if (isPalindrome[j + 1][i]) { // if [j+1...i] is a palindrome then we can cut [0...i] as [0...j] and [j+1...i]
					dp[i] = min(dp[i], 1 + dp[j]);
				}
			}
		}
	}

	return dp[n - 1];
}

int main() {
	string s;
	cin >> s;

	cout << palindromicPartition(s) << endl;

	return 0;
}