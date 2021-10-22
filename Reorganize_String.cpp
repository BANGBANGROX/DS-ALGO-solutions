#include<bits/stdc++.h>
using namespace std;

string reorganizeString(string s) {
	vector<int> freq(26);
	int n = s.size();
	char lastCharacter = NULL;
	string res("");

	for (int i = 0; i < n; ++i) {
		++freq[s[i] - 'a'];
	}

	for (int i = 0; i < n; ++i) {
		char newCharacter = NULL;
		int maxF = 0;
		for (int j = 0; j < 26; ++j) {
			if (char(j + 'a') != lastCharacter && freq[j] > maxF) {
				maxF = freq[j];
				newCharacter = j + 'a';
			}
		}
		if (newCharacter == NULL) return "";
		--freq[newCharacter - 'a'];
		res += newCharacter;
		lastCharacter = newCharacter;
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		cout << reorganizeString(s) << endl;
	}

	return 0;
}