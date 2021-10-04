#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> graph[N];
int tin[N], tout[N], timer;

void dfs(int node, int par) {
	tin[node] = ++timer;

	for (int child : graph[node]) {
		if (child != par) dfs(child, node);
	}

	tout[node] = ++timer;
}

void makeGraph(vector<pair<int, int>>& g) {
	for (pair<int, int> x : g) {
		graph[x.first].push_back(x.second);
		graph[x.second].push_back(x.first);
	}
}

bool isPossible(int x, int y) {
	return tin[y] > tin[x] && tout[y] < tout[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<pair<int, int>> g;

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g.push_back({ u,v });
	}

	makeGraph(g);

	dfs(1, -1);

	int q;
	cin >> q;

	while (q--) {
		int code, x, y;
		cin >> code >> x >> y;

		if (code == 0) {
			bool ans = isPossible(x, y);
			if (ans) cout << "YES\n";
			else cout << "NO\n";
		}

		if (code == 1) {
			bool ans = isPossible(y, x);
			if (ans) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}