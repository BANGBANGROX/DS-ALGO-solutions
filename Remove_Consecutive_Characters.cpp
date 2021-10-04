#include<bits/stdc++.h>
using namespace std;

void util(string& res, string& s, int i, int n) {
	if (i == n) {
		return;
	}

	if (i != 0 && s[i] == res.back()) {
		util(res, s, i + 1, n);
		return;
	}

	res.push_back(s[i]);
	util(res, s, i + 1, n);
}

string removeConsecutiveCharacter(string s) {
	string res("");

	util(res, s, 0, s.size());

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << removeConsecutiveCharacter(s) << endl;
	}

	return 0;
}