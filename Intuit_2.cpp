#include<bits/stdc++.h>
using namespace std;

int solve(int n, char word[]) {
	if (n > 26) return -1;

	int freq[26] = { 0 }, res = 0;

	for (int i = 0; i < n; ++i) ++freq[word[i] - 'a'];

	for (int i = 0; i < 26; ++i) {
		if (freq[i]) res += (freq[i] - 1);
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		char* word = new char[n];
		for (int i = 0; i < n; ++i) cin >> word[i];

		cout << solve(n, word) << endl;
	}

	return 0;
}