#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void dfs(int node, vector<vector<int>>& graph, vector<int>& currPath, vector<bool> vis, int target) {
	if (node == target) {
		currPath.push_back(node);
		ans.push_back(currPath);
		currPath.pop_back();
		return;
	}

	vis[node] = 1;
	currPath.push_back(node);

	for (int child : graph[node]) {
		if (!vis[child]) {
			dfs(child, graph, currPath, vis, target);
		}
	}

	currPath.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	int target = graph.size() - 1;
	vector<bool> vis(target + 1);
	vector<int> currPath;

	dfs(0, graph, currPath, vis, target);

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> graph(n);
		for (int i = 0; i < n; ++i) {
			int size;
			cin >> size;
			while (size--) {
				int a;
				cin >> a;
				graph[i].push_back(a);
			}
		}

		ans.clear();

		vector<vector<int>> ans = allPathsSourceTarget(graph);
		for (vector<int> x : ans) {
			for (int y : x) cout << y << " ";
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
