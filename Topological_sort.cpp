#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& res, vector<int>* graph, vector<bool>& vis) {
	vis[node] = 1;
	
	for (int child : graph[node]) {
		if (!vis[child]) dfs(child, res, graph, vis);
	}

	res.push_back(node);
}

vector<int> topoSort(int n, vector<int>* graph) {
	vector<int> res;
	vector<bool> vis(n);
	
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i, res, graph, vis);
		}
	}
	reverse(res.begin(), res.end());

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int>* graph = new vector<int>[n];
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}

		vector<int> res = topoSort(n, graph);

		for (int x : res) cout << x << " ";
		cout << endl;
	}

	return 0;
}