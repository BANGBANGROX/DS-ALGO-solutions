#include<bits/stdc++.h>
using namespace std;

class Solution {
	const int mod = 1e9 + 7;

	int decodeOneCharacter(char ch) {
		if (ch == '*') return 9;

		if (ch == '0') return 0;

		return 1;
	}

	int decodeTwoCharacters(char first, char second) {
		if (first == '*') {
			if (second == '*') return 15;
			if (second >= '0' && second <= '6') return 2;
			return 1;
		}

		if (first == '1') {
			if (second == '*') return 9;
			if (second >= '0' && second <= '9') return 1;
			return 0;
		}

		if (first == '2') {
			if (second == '*') return 6;
			if (second >= '0' && second <= '6') return 1;
			return 0;
		}

		return 0;
	}

public:
	int numDecodings(string s) {
		int n = s.size();
		long a = 1;
		long b = decodeOneCharacter(s[0]);

		for (int i = 2; i <= n; ++i) {
			char first = s[i - 2];
			char second = s[i - 1];
			long value1 = (b * decodeOneCharacter(second)) % mod;
			long value2 = (a * decodeTwoCharacters(first, second)) % mod;
			long c = (value1 + value2) % mod;
			a = b;
			b = c;
		}

		return (int)b;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution obj;
		cout << obj.numDecodings(s) << endl;
	}

	return 0;
}