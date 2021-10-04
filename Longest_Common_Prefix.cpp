#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	int minLen = INT_MAX, n = strs.size();
	string str("");

	for (int i = 0; i < n; ++i) {
		if (minLen > strs[i].size()) {
			minLen = strs[i].size();
			str = strs[i];
		}
	}

	for (int i = 0; i < minLen; ++i) {
		for (int j = 0; j < n; ++j) {
			if (str[i] != strs[j][i]) {
				return str.substr(0, i);
			}
		}
	}

	return str;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<string> strs(n);
		for (int i = 0; i < n; ++i) cin >> strs[i];

		cout << longestCommonPrefix(strs) << endl;
	}
}