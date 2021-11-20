#include<bits/stdc++.h>
using namespace std;

bool isValid(char ch) {
	return islower(ch) || ch == '-' || ch == '.' || ch == ',' || ch == '!';
}

int countValidWords(string s) {
	int words = 0;
	int n = s.size();

	for (int i = 0; i < n; ++i) {
		string temp("");
		int hyphen = 0, pos = -1, punchuation = 0, punchPos = -1;
		bool isCorrect = true;
		while (i < n && s[i] != ' ') {
			temp += s[i];
			++i;
		}
		if (temp == "") continue;
		//cout << temp << endl;
		for (int j = 0; j < temp.size(); ++j) {
			if (!isValid(temp[j])) {
				isCorrect = false;
				break;
			}
			if (islower(temp[j])) continue;
			if (temp[j] == '-') {
				++hyphen;
				pos = j;
			}
			if (temp[j] == '.' || temp[j] == ',' || temp[j] == '!') {
				++punchuation;
				punchPos = j;
			}
		}
		if (!isCorrect || hyphen > 1 || punchuation > 1) {
			//cout << temp << " 1" << endl;
			continue;
		}
		if (hyphen == 1 && ((pos == 0 || pos == temp.size() - 1) || !isalpha(temp[pos - 1]) || !isalpha(temp[pos + 1]))) {
			//cout << temp << " 2" << endl;
			continue;
		}
		if (punchuation == 1 && punchPos != temp.size() - 1) {
			//cout << temp << " 3" << endl;
			continue;
		}
		++words;
	}

	return words;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		getline(cin, s);
		getline(cin, s);

		cout << countValidWords(s) << endl;
	}

	return 0;
}