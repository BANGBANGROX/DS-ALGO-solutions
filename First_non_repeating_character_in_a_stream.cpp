#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string s) {
	list<char> v;
	vector<int> freq(26);
	int n = s.size();

	for (int i = 0; i < n; ++i) {
		++freq[s[i] - 'a'];
		if (freq[s[i] - 'a'] == 1) v.push_back(s[i]);
		while (!v.empty() && freq[v.front() - 'a'] > 1) v.pop_front();
		if (v.empty()) s[i] = '#';
		else s[i] = v.front();
	}

	return s;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		cout << FirstNonRepeating(s) << endl;
	}

	return 0;
}
