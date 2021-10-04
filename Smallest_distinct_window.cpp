#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

string findSubString(string s) {
	int n = s.size();
	unordered_map<char, int> hash;

	for (int i = 0; i < n; ++i) {
		hash[s[i]] = 0;
	}

	int l = 0, r = 0; // We consider window l...r-1
	int minLen = INT_MAX, startIndex = 0, cnt = 0;
    
	while (r < n) {
		if (hash[s[r]] == 0) ++cnt;
		++hash[s[r]];

		if (cnt == hash.size()) {
			while (l < n && hash[s[l]] > 1) {
				--hash[s[l]];
				++l;
			}
			if (r - l + 1 < minLen) {
				minLen = r - l + 1;
				startIndex = l;
			}
		}
	}

	return s.substr(startIndex, minLen);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << findSubString(s) << endl;
	}

	return 0;
}
