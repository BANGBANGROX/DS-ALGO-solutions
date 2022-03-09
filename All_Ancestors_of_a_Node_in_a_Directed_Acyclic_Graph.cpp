#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector<vector<int>> ans;
		vector<set<int>> initial(n);
		vector<vector<int>> graph(n);
		vector<int> inDegree(n);
		queue<int> q;

		for (const vector<int>& edge : edges) {
			int u = edge[0];
			int v = edge[1];
			++inDegree[v];
			graph[u].push_back(v);
		}

		for (int i = 0; i < n; ++i) {
			if (inDegree[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int child : graph[node]) {
				--inDegree[child];
				initial[child].insert(node);
				for (int ancestor : initial[node]) {
					initial[child].insert(ancestor);
				}
				if (inDegree[child] == 0) q.push(child);
			}
		}
        
		for (int i = 0; i < n; ++i) {
			if (initial[i].empty()) {
				ans.push_back({});
				continue;
			}
			vector<int> ancestors(initial[i].begin(), initial[i].end());
			ans.push_back(ancestors);
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> edges;
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			edges.push_back({ a,b });
		}

		Solution solution;
		vector<vector<int>> ans = solution.getAncestors(n, edges);
		for (const vector<int>& x : ans) {
			for (const int& y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}