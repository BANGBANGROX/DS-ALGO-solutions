#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> edges[N];
int mul(int a, int b)
{
	return ((ll)a * b) % mod;
}
pair<int, int> dfs(int node, int parent)
{
	int all_white = 1; // can the vertex be colored black (no children black)
	int something_black = 0; // vertex to be colored white
	for (int child : edges[node])
	{
		if (child != parent)
		{
			pair<int, int> res_child = dfs(child, node); // result for the current child
			int temp_white = all_white; // storing prevoius value so as to use it later
			all_white = mul(all_white, res_child.second); // updating all_white by the number of ways to color the child white so that the parent
			                                              // can be colored black
			something_black = (mul(temp_white, res_child.first) + mul(something_black, res_child.first + res_child.second)) % mod; // to color white we can simply take 
																																  //  children as white or black
		}
	}
	return { all_white,(all_white + something_black) % mod }; // black is only black but white can be both
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	pair<int, int> res = dfs(1, -1);
	cout << (res.first + res.second) % mod << "\n";
	return 0;
}