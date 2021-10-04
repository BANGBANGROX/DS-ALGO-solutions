#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> vis;
vector<int> graph[100005];
int nn = 0;

void dfs(int node) {
	vis[node] = 1;
	++nn;

	for (int child : graph[node]) {
		if (!vis[child]) dfs(child);
	}
}

int journeyToMoon(int n, vector<vector<int>>& astronaut) {
	vis.resize(n);

	for (vector<int> x : astronaut) {
		graph[x[0]].push_back(x[1]);
		graph[x[1]].push_back(x[0]);
	}

	ll res = 1LL * n * ((ll)n - 1) / 2;

	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			nn = 0;
			dfs(i);
			res = res - 1LL * nn * ((ll)nn - 1) / 2;
		}
	}

	return (int)res;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> astronaut(m, vector<int>(2));

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		astronaut.push_back({ u,v });
	}

	cout << journeyToMoon(n, astronaut) << endl;

	return 0;
}