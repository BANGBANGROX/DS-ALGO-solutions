#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minSteps(string s, string t) {
		int ans = 0;
		vector<int> freq(26);

		for (char& c : s) ++freq[c - 'a'];

		for (char& c : t) --freq[c - 'a'];

		for (int i = 0; i < 26; ++i) ans += abs(freq[i]);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s, t;
		cin >> s >> t;

		Solution solution;
		cout << solution.minSteps(s, t) << endl;
	}

	return 0;
}