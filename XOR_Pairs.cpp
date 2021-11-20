#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;

vector<int> tree[N];
int subXor[N], values[N];

void dfs(int node, int par) {
	subXor[node] ^= values[node];

	for (int child : tree[node]) {
		if (child != par) {
			dfs(child, node);
			subXor[node] ^= subXor[child];
		}
	}
}

int main() {
	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; ++i) cin >> values[i];

	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, -1);

	ll pairs = 0;
	unordered_map<int, int> occ;

	for (int i = 1; i <= n; ++i) {
		++occ[subXor[i]];
	}

	for (int i = 1; i <= n; ++i) {
		int a = subXor[i];
		int b = x ^ a;
		pairs += 2 * (ll)min(occ[a], occ[b]);
		occ[a] = 0;
		occ[b] = 0;
	}

	cout << pairs << endl;

	return 0;
}
