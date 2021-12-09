#include<bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
	vector<int> ans, last(26);
	int n = s.size(), pos = 0, anchor = 0;

	for (int i = 0; i < n; ++i) {
		last[s[i] - 'a'] = i;
	}

	for (int i = 0; i < n; ++i) {
		pos = max(pos, last[s[i] - 'a']);
		if (i == pos) {
			ans.push_back(i - anchor + 1);
			anchor = i + 1;
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		vector<int> ans = partitionLabels(s);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}