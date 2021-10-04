#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

void generateParanthesisUtil(string curr, int balancing, int n) {
	if (curr.size() == 2 * n) {
		if(balancing == 0) ans.push_back(curr);
		return;
	}

	if (balancing == 0) {
		curr.push_back('(');
		generateParanthesisUtil(curr, balancing + 1, n);
		curr.pop_back();
	}
	else {
		curr.push_back(')');
		generateParanthesisUtil(curr, balancing - 1, n);
		curr.pop_back();
		if (balancing < n) {
			curr.push_back('(');
			generateParanthesisUtil(curr, balancing + 1, n);
			curr.pop_back();
		}
	}
}

vector<string> generateParenthesis(int n) {
	ans.clear();
	string empty("");
	generateParanthesisUtil(empty, 0, n);
	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		vector<string> res = generateParenthesis(n);
		for (string s : res) cout << s << endl;
	}

	return 0;
}