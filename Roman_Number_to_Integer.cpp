#include<bits/stdc++.h>
using namespace std;

int value(char ch) {
	if (ch == 'I') return 1;
	
	if (ch == 'V') return 5;

	if (ch == 'X') return 10;

	if (ch == 'L') return 50;

	if (ch == 'C') return 100;

	if (ch == 'D') return 500;

	if (ch == 'M') return 1000;

	return -1;
}

int romanToDecimal(string& s) {
	int n = s.size(), decimalNumber = 0;

	for (int i = 0; i < n - 1; ++i) {
		int v1 = value(s[i]), v2 = value(s[i + 1]);
		if (v1 < v2) decimalNumber -= v1;
		else decimalNumber += v1;
	}
	decimalNumber += value(s[n - 1]);

	return decimalNumber;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << romanToDecimal(s) << endl;
	}

	return 0;
}