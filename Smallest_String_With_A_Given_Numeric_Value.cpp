// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string getSmallestString(int n, int k) {
		string ans("");

		for (int i = 1; i <= n; ++i) {
			for (char ch = 'a'; ch <= 'z'; ++ch) {
				if (k - (ch - 'a' + 1) <= (n - i) * 26) {
					ans += ch;
					k -= (ch - 'a' + 1);
					break;
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
		int n, k;
		cin >> n >> k;

		Solution solution;
		cout << solution.getSmallestString(n, k) << endl;
	}

	return 0;
}