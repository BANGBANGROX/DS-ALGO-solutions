#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool isPalindrome(string s, int l, int r) {
		while (l < r) {
			if (s[l] != s[r]) return false;
			++l;
			--r;
		}

		return true;
	}

public:
	bool validPalindrome(string s) {
		int n = s.size();
		int l = 0;
		int r = n - 1;
		bool operationDone = false;

		while (l < r) {
			if (s[l] == s[r]) {
				++l;
				--r;
			}
			else {
				return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
			}
		}

		return true;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		if (solution.validPalindrome(s)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}