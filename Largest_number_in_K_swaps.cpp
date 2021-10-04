#include<bits/stdc++.h>
using namespace std;

void findMaximum(string& s, string& maxNum, int pos, int k) {
	if (k == 0) return;

	char ch = s[pos];
	int n = s.size(), maxPos = pos;
	for (int i = pos + 1; i < n; ++i) {
		if (ch < s[i]) {
			maxPos = i;
			ch = s[i];
		}
	}
	if (ch != s[pos]) --k;
	for (int i = n - 1; i >= pos; --i) {
		if (s[i] == ch) {
			swap(s[i], s[pos]);
			if (s.compare(maxNum) > 0) {
				maxNum = s;
			}
			findMaximum(s, maxNum, pos + 1, k);
			swap(s[i], s[pos]);
		}
	}
}

string findMaximumNum(string s, int k) {
	string maxNum = s;
	
	findMaximum(s, maxNum, 0, k);

	return maxNum;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int k;
		cin >> k;
		
		cout << findMaximumNum(s, k) << endl;
	}

	return 0;
}
