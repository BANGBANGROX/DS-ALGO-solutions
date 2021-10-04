#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>* graph, vector<bool>& vis, vector<bool>& recStack) {
	vis[node] = 1;
	recStack[node] = 1;

	for (int child : graph[node]) {
		if (!vis[child] && dfs(child, graph, vis, recStack)) return true;
		else if (recStack[child]) return true;
	}

	recStack[node] = 0;
	return false;
}

bool isCyclic(int n, vector<int> graph[]) {
	vector<bool> vis(n);
	vector<bool> recStack(n);

	for (int i = 0; i < n; ++i) {
		if (!vis[i] && dfs(i, graph, vis, recStack)) return true;
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
		}

		bool res = isCyclic(n, graph);

		if (res) cout << "CYCLIC\n";
		else cout << "NOT CYCLIC\n";
	}

	return 0;
}
