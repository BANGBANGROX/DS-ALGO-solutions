#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>* graph, vector<bool>& vis, int par) {
	vis[node] = 1;

	for (int child : graph[node]) {
		if (child == par) continue;
		if (vis[child]) return true;
		else if (dfs(child, graph, vis, node)) return true;
	}

	return false;
}

bool isCyclic(int n, vector<int>* graph) {
	vector<bool> vis(n);

	for (int i = 0; i < n; ++i) {
		if (!vis[i] && dfs(i, graph, vis, -1)) return true;
	}

	return false;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int>* graph = new vector<int>[n];

		while (m--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		bool res = isCyclic(n, graph);

		if (res) cout << "CYCLIC\n";
		else cout << "NOT CYCLIC\n";
	}

	return 0;
}
