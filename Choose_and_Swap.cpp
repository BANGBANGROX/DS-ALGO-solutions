#include<bits/stdc++.h>
using namespace std;

string chooseandswap(string s) {
	vector<int> firstOccurence(26, -1);
	int n = s.size(), newCharacter = -1, oldCharacter = -1;
	bool flag = false;

	for (int i = 0; i < n; ++i) {
		if (firstOccurence[s[i] - 'a'] == -1) {
			firstOccurence[s[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < s[i] - 'a'; ++j) {
			if (firstOccurence[j] > firstOccurence[s[i] - 'a']) {
				flag = true;
				newCharacter = j;
				oldCharacter = i;
				break;
			}
		}
		if (flag) break;
	}

	if (!flag) return s;

	char newCh = char(newCharacter + 'a');
	char oldCh = s[oldCharacter];

	for (int i = 0; i < n; ++i) {
		if (s[i] == oldCh) {
			s[i] = newCh;
		}
		else if (s[i] == newCh) {
			s[i] = oldCh;
		}
	}

	return s;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << chooseandswap(s) << endl;
	}

	return 0;
}