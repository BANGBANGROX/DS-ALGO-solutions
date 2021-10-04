#include<bits/stdc++.h>
using namespace std;
const int N = 101;

bool isSafe(bool graph[N][N], int c, int color[], int v, int V) {
	for (int i = 0; i < V; ++i) {
		if (graph[v][i] && c == color[i]) {
			return false;
		}
	}

	return true;
}

bool graphColoringUtil(bool graph[N][N], int color[], int m, int v, int V) {
	if (v == V) return true;

	for (int c = 1; c <= m; ++c) {
		if (isSafe(graph, c, color, v, V)) {
			color[v] = c;
			if (graphColoringUtil(graph, color, m, v + 1, V)) return true;
			color[v] = 0;
		}
	}

	return false;
}

bool graphColoring(bool graph[N][N], int m, int V) {
	int color[N];
	memset(color, 0, sizeof(color));
	return graphColoringUtil(graph, color, m, 0, V);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		bool graph[N][N];
		memset(graph, 0, sizeof(graph));
		int E, V, m;
		cin >> E >> V >> m;
		for (int i = 0; i < V; ++i) {
			int a, b;
			cin >> a >> b;
			graph[a - 1][b - 1] = 1;
			graph[b - 1][a - 1] = 1;
		}

		cout << graphColoring(graph, m, V) << endl;
	}

	return 0;
}