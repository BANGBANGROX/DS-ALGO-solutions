#include<bits/stdc++.h>
using namespace std;

bool isBracket(char ch) {
	return ch == '(' || ch == ')';
}

bool isValid(string s) {
	int cnt = 0, n = s.size();
	
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') ++cnt;
		else if (s[i] == ')') --cnt;
		if (cnt < 0) return false;
	}

	return cnt == 0;
}

vector<string> removeInvalidParentheses(string s) {
	if (s.empty()) return {};
	queue<string> q;
	vector<string> ans;
	set<string> vis;

	q.push(s);
	vis.insert(s);
	bool correct = false;

	while (!q.empty()) {
		string str = q.front();
		q.pop();
		if (isValid(str)) {
			ans.push_back(str);
			correct = true;
		}
		if (correct) continue;
		for (int i = 0; i < str.size(); ++i) {
			if (!isBracket(str[i])) continue;
			string newStr = str.substr(0, i) + str.substr(i + 1);
			if (vis.find(newStr) == vis.end()) {
				vis.insert(newStr);
				q.push(newStr);
			}
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

		vector<string> ans = removeInvalidParentheses(s);
		for (string x : ans) cout << x << endl;
	}

	return 0;
}
