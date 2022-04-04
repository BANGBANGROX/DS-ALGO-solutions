#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<bool> visited;
	vector<bool> safeNodes; // safeNodes[i] = true if node i is safe else false

	void dfs(int node, vector<vector<int>>& graph) {
		bool isSafe = true;

		visited[node] = true;

		for (int child : graph[node]) {
			if (!visited[child]) {
				dfs(child, graph);
			}
			isSafe &= safeNodes[child];
		}

		safeNodes[node] = isSafe;
	}

public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> ans;
		visited = safeNodes = vector<bool>(n);

		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(i, graph);
			}
		}

		for (int i = 0; i < n; ++i) {
			if (safeNodes[i]) ans.push_back(i);
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> graph(n);
		for (int i = 0; i < n; ++i) {
			int m;
			cin >> m;
			graph[i] = vector<int>(m);
			for (int j = 0; j < m; ++j) {
				cin >> graph[i][j];
			}
		}

		Solution solution;
		vector<int> ans = solution.eventualSafeNodes(graph);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}