#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

unordered_map<string, vector<string>> graph;
set<string> vis;

void dfs(vector<string>& acc, string node) {
	vis.insert(node);
	acc.push_back(node);

	for (string child : graph[node]) {
		if (vis.find(child) == vis.end()) dfs(acc, child);
	}
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	vector<vector<string>> ans;

	for (vector<string> acc : accounts) {
		string acc1 = acc[1];
		for (int i = 2; i < acc.size(); ++i) {
			graph[acc1].push_back(acc[i]);
			graph[acc[i]].push_back(acc1);
		}
	}

	for (vector<string> acc : accounts) {
		string name = acc[0], firstEmail = acc[1];
		if (vis.find(firstEmail) == vis.end()) {
			vector<string> merged;
			merged.push_back(name);
			dfs(merged, firstEmail);
			sort(merged.begin() + 1, merged.end());
			ans.push_back(merged);
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<string>> accounts(n);
		for (int i = 0; i < n; ++i) {
			int m;
			string s;
			cin >> m;
			cin >> s;
			accounts[i].push_back(s);
			for (int j = 1; j <= m; ++j) {
				cin >> s;
				accounts[i].push_back(s);
			}
		}

		vector<vector<string>> ans = accountsMerge(accounts);
		for (vector<string> x : ans) {
			for (string y : x) cout << y << " ";
			cout << endl;
		}
		cout << endl;

		graph.clear();
		vis.clear();
	}

	return 0;
}