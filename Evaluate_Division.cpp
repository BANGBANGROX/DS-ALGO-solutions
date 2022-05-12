#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool found;
	double value;

	void dfs(map<string, vector<string>>& graph, string& node,
		map<string, bool>& visited, map<string, double>& values, string& end) {
		visited[node] = true;

		if (node.compare(end) == 0) {
			found = true;
			return;
		}

		if (found) return;

		for (string& child : graph[node]) {
			if (visited.find(child) == visited.end()) {
				value *= values[node + "->" + child];
				if (child.compare(end) == 0) {
					found = true;
					return;
				}
				dfs(graph, child, visited, values, end);
				if (found) return;
				else value /= values[node + "->" + child];
			}
		}
	}

public:
	vector<double> calcEquation(vector<vector<string>>& equations,
		vector<double>& values, vector<vector<string>>& queries) {
		map<string, vector<string>> graph;
		map<string, double> valuesOfPair;
		vector<double> ans;
		int n = values.size();

		for (int i = 0; i < n; ++i) {
			string u = equations[i][0];
			string v = equations[i][1];
			graph[u].push_back(v);
			graph[v].push_back(u);
			valuesOfPair[u + "->" + v] = values[i];
			valuesOfPair[v + "->" + u] = 1 / values[i];
		}

		for (const vector<string>& query : queries) {
			string start = query[0];
			string end = query[1];
			found = false;
			value = 1;
			map<string, bool> visited;
			if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
				ans.push_back(-1);
				continue;
			}
			dfs(graph, start, visited, valuesOfPair, end);
			if (found) ans.push_back(value);
			else ans.push_back(-1);
		}

		return ans;
	}
};


int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, q;
		cin >> n;
		vector<vector<string>> equations(n, vector<string>(2));
		for (int i = 0; i < n; ++i) {
			cin >> equations[i][0] >> equations[i][1];
		}
		vector<double> values(n);
		for (int i = 0; i < n; ++i) {
			cin >> values[i];
		}
		cin >> q;
		vector<vector<string>> queries(q, vector<string>(2));
		for (int i = 0; i < q; ++i) {
			cin >> queries[i][0] >> queries[i][1];
		}

		Solution solution;
		vector<double> ans = solution.calcEquation(equations, values, queries);
		for (double& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}