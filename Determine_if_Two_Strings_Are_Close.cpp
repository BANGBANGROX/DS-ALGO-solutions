#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool closeStrings(string word1, string word2) {
		vector<int> count1(26);
		vector<int> count2(26);
		vector<bool> present1(26);
		vector<bool> present2(26);

		for (char ch : word1) {
			++count1[ch - 'a'];
			present1[ch - 'a'] = true;
		}

		for (char ch : word2) {
			++count2[ch - 'a'];
			present2[ch - 'a'] = true;
		}

		sort(count1.begin(), count1.end());
		sort(count2.begin(), count2.end());

		return count1 == count2 && present1 == present2;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string word1;
		cin >> word1;
		string word2;
		cin >> word2;

		Solution solution;
		if (solution.closeStrings(word1, word2)) {
			cout << "true\n";
		}
		else {
			cout << "false\n";
		}
	}

	return 0;
}