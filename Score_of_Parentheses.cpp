// https://leetcode.com/problems/score-of-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int scoreOfParentheses(string s) {
		int ans = 0;
		int balance = 0;
		int n = s.size();

		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') ++balance;
			else {
				--balance;
				if (s[i - 1] == '(') {
					ans += (1 << balance);
				}
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
		cout << solution.scoreOfParentheses(s) << endl;
	}

	return 0;
}