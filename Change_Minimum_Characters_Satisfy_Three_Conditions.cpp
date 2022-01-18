#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minCharacters(string a, string b) {
		int m = a.size();
		int n = b.size();
		int ans = m + n;
		vector<int> freqA(26);
		vector<int> freqB(26);

		for (char ch : a) {
			++freqA[ch - 'a'];
		}

		for (char ch : b) {
			++freqB[ch - 'a'];
		}

		for (int i = 0; i < 26; ++i) {
			// Condition 3
			// We try and make every character of a and b equal to 'a' + i
			ans = min(ans, m - freqA[i] + n - freqB[i]);

			if (i > 0) {
				freqA[i] += freqA[i - 1];
				freqB[i] += freqB[i - 1];

				// Condition 1 
				// We make every character in a less than 'a' + i and every character in b greater than or equal to
				// 'a' + i
				ans = min(ans, freqB[i - 1] + m - freqA[i - 1]);

				// Condition2
				// We make every character in b less than 'a' + i and every character in a greater than or equal to
				// 'a' + i
				ans = min(ans, freqA[i - 1] + n - freqB[i - 1]);
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string a, b;
		cin >> a >> b;

		Solution solution;
		cout << solution.minCharacters(a, b) << endl;
	}

	return 0;
}