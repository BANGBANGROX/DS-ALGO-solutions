#include<bits/stdc++.h>
using namespace std;

string shortestPalindrome(string s) {
	int n = s.size(), xorNum = 0, i = n - 1;

	for (char c : s) xorNum ^= (int)c;

	while (i > 0) {
		bool parity = i % 2;
		if ((parity && xorNum == 0) || (!parity && xorNum == (int)s[i >> 1])) {
			int l = 0, r = i;
			bool isPalindrome = true;
			while (l < r) {
				if (s[l] != s[r]) {
					isPalindrome = false;
					break;
				}
				++l;
				--r;
			}
			if (isPalindrome) {
				break;
			}
		}
		xorNum ^= (int)s[i];
		--i;
	}

	string res = s.substr(i + 1);
	reverse(res.begin(), res.end());
	res += s;

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << shortestPalindrome(s) << endl;
	}

	return 0;
}