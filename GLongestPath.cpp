#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> edges[N];
int dist[N], in_deg[N], vis[N], n, m; // in_deg[i] is the number of edges coming into node i
void dfs(int node)
{
	assert(!vis[node]);
	vis[node] = 1;
	for (int child : edges[node])
	{
		dist[child] = max(dist[child], 1 + dist[node]);
		--in_deg[child];
		if (!in_deg[child]) dfs(child);
	}
}
int main()
{
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		++in_deg[b];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i] && in_deg[i] == 0) dfs(i);
	}
	int res = *max_element(dist + 1, dist + n + 1);
	cout << res << "\n";
}