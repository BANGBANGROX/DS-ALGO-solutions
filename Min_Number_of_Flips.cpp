#include<bits/stdc++.h>
using namespace std;

int calculate(bool first, string& s) {
	int n = s.size(), res = 0;

	for (int i = 0; i < n; ++i) {
		res += abs(s[i] - first - '0');
		first = 1 - first;
	}

	return res;
}

int minFlips(string s) {
	int ansWith1 = calculate(1, s);
	int ansWith0 = calculate(0, s);

	return min(ansWith1, ansWith0);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << minFlips(s) << endl;
	}

	return 0;
}
