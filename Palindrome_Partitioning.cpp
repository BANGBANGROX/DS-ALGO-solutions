#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int low, int high) {

	while (low < high) {
		if (s[low] != s[high]) {
			return false;
		}
		++low;
		--high;
	}

	return true;
}

void partitionUtil(vector<vector<string>>& ans, vector<string>& curr, int start, string s) {
	if (start >= (int)s.size()) {
		ans.push_back(curr);
		return;
	}

	for (int i = start; i < s.size(); ++i) {
		if (isPalindrome(s, start, i)) {
			curr.push_back(s.substr(start, i - start + 1));
			partitionUtil(ans, curr, i + 1, s);
			curr.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> ans;
	vector<string> curr;

	partitionUtil(ans, curr, 0, s);

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		vector<vector<string>> ans = partition(s);

		for (int i = 0; i < ans.size(); ++i) {
			for (string res : ans[i]) cout << res << " ";
		}
		cout << endl;
	}

	return 0;
}