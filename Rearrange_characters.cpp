#include<bits/stdc++.h>
using namespace std;

string rearrangeString(string s) {
	vector<int> freq(26);
	int n = s.size();
	string res("");
	char prevChar = '\0';

	for (int i = 0; i < n; ++i) ++freq[s[i] - 'a'];

	for (int i = 0; i < n; ++i) {
		char ch = '\0';
		int maxFreq = 0;
		for (int j = 0; j < 26; ++j) {
			if (prevChar != j + 'a') {
				if (maxFreq < freq[j]) {
					maxFreq = freq[j];
					ch = j + 'a';
				}
			}
		}
		if (ch == '\0') return "-1";
		res.push_back(ch);
		--freq[ch - 'a'];
		prevChar = ch;
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << rearrangeString(s) << endl;
	}

	return 0;
}