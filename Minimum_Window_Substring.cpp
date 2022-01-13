#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int n = s.size();
		int m = 0;
		int left = 0;
		int right = 0;
		int satisfied = 0;
		int start = 0;
		int end = n;
		vector<int> freqT(256), freqS(256);

		if (n < t.size()) return "";

		for (char ch : t) {
			if (freqT[ch] == 0) ++m;
			++freqT[ch];
		}

		while (right < n) {
			++freqS[s[right]];
			if (freqS[s[right]] == freqT[s[right]]) ++satisfied;
			if (satisfied == m) {
				while (freqS[s[left]] > freqT[s[left]]) {
					--freqS[s[left]];
					++left;
				}
				int currentLength = right - left + 1;
				int previousLength = end - start + 1;
				if (previousLength > currentLength) {
					start = left;
					end = right;
				}
			}
			++right;
		}

		if (end == n) return "";

		return s.substr(start, end - start + 1);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		string t;
		cin >> t;

		Solution solution;
		cout << solution.minWindow(s, t) << endl;
	}

	return 0;
}