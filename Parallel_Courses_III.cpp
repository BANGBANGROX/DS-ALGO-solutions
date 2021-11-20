#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<vector<int>>& graph, vector<int>& score, vector<int>& time, vector<bool>& vis) {
	if (vis[node]) return;

	vis[node] = 1;
	score[node] += time[node - 1];

	int maxValue = 0;

	for (int child : graph[node]) {
		dfs(child, node, graph, score, time, vis);
		maxValue = max(maxValue, score[child]);

	}

	score[node] += maxValue;
}

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
	vector<vector<int>> graph(n + 1);
	vector<int> score(n + 1);
	vector<bool> vis(n + 1);

	for (vector<int> r : relations) {
		int u = r[0], v = r[1];
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		dfs(i, -1, graph, score, time, vis);
	}

	return *max_element(score.begin(), score.end());
}
