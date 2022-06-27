// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
	typedef long long ll;

	vector<vector<int>> tree;

	bool check(int node, int parent, ll waterLeft, int cap[]) {
		if (waterLeft < cap[node - 1]) return false;

		int size = tree[node].size();

		if (parent != -1) --size;

		for (int child : tree[node]) {
			if (child != parent) {
				if (!check(child, node, (waterLeft - cap[node - 1]) / size, cap)) return false;
			}
		}

		return true;
	}

public:
	ll minimum_amount(vector<vector<int>>& edges, int n, int s, int* cap) {
		// Code here
		tree = vector<vector<int>>(n + 1);

		for (vector<int>& edge : edges) {
			int u = edge[0];
			int v = edge[1];
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		ll l = 1;
		ll r = 1e18;
		ll ans = -1;

		while (l <= r) {
			ll mid = (l + ((r - l) >> 1));
			if (check(s, -1, mid, cap)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		return ans;
	}
};

// { Driver Code Starts.


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int num, start;
		cin >> num >> start;
		int* cap = new int[num];
		for (int i = 0; i < num; i++)
			cin >> cap[i];

		vector<vector<int>> Edges(num - 1);
		for (int i = 1; i < num; i++) {
			int u, v; cin >> u >> v;
			Edges[i - 1].push_back(u);
			Edges[i - 1].push_back(v);
		}


		Solution obj;
		long long ans = obj.minimum_amount(Edges, num, start, cap);
		cout << ans << endl;

	}

	return 0;
}  // } Driver Code Ends