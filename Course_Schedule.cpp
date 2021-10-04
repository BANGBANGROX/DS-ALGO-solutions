#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>* graph, vector<bool>& vis, vector<bool>& recStack) {
	vis[node] = 1;
	recStack[node] = 1;

	for (int child : graph[node]) {
		if (vis[child]) return true;
		if (!vis[child] && dfs(child, graph, vis, recStack)) return true;
		else if (recStack[child]) return true;
	}
	recStack[node] = 0;

	return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<bool> vis(numCourses), recStack(numCourses);
	vector<int>* graph = new vector<int>[numCourses];
	int m = prerequisites.size();

	for (int i = 0; i < m; ++i) {
		int a = prerequisites[i][0];
		int b = prerequisites[i][1];
		graph[b].push_back(a);
	}

	for (int i = 0; i < numCourses; ++i) {
		if (!vis[i] && dfs(i, graph, vis, recStack)) return false;
	}

	return true;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> pre(m, vector<int>(2));

		for (int i = 0; i < m; ++i) {
			cin >> pre[i][0] >> pre[i][1];
		}

		cout << canFinish(n, pre);
	}
}