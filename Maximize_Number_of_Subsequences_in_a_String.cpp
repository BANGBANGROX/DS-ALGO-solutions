// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	ll maximumSubsequenceCount(string text, string pattern) {
		int n = text.size();
		char firstLetter = pattern[0];
		char secondLetter = pattern[1];
		int firstCount = 0;
		int secondCount = 0;
		ll ans = 0;

		for (int i = 0; i < n; ++i) {
			if (text[i] == firstLetter) ++firstCount;
			else if (text[i] == secondLetter) {
				++secondCount;
				ans += (ll)firstCount;
			}
		}

		if (firstLetter == secondLetter) {
			++firstCount;
			ans = (ll)firstCount * ((ll)firstCount - 1) / 2;
			return ans;
		}

		ans += (ll)max(firstCount, secondCount);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string text, pattern;
		cin >> text >> pattern;

		Solution solution;
		cout << solution.maximumSubsequenceCount(text, pattern) << endl;
	}

	return 0;
}