#include<bits/stdc++.h>
using namespace std;

vector<int> graph[300];
int vis[300];

void topoSort(int node, string& res) {
	vis[node] = 1;

	for (int child : graph[node]) {
		if (!vis[child]) {
			topoSort(child, res);
		}
	}
	char ch = node;

	res.push_back(ch);
}

string findOrder(string dict[], int n, int k) {
	string res("");
	for (int i = 0; i < 300; ++i) {
		graph[i].clear();
		vis[i] = 0;
	}

	for (int i = 0; i < n - 1; ++i) {
		string s1 = dict[i];
		string s2 = dict[i + 1];
		int j = 0;
		while (s1[j] == s2[j]) {
			++j;
		}
		graph[s1[j]].push_back(s2[j]);
	}

	for (int i = 97; i < 97 + k; ++i) {
		if (!vis[i]) {
			topoSort(i, res);
		}
	}
	reverse(res.begin(), res.end());

	return res;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		string* dict = new string[n];
		for (int i = 0; i < n; ++i) {
			cin >> dict[i];
		}

		cout << findOrder(dict, n, k) << endl;
	}

	return 0;
}
