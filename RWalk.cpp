#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n;
int mult(int a, int b)
{
	return ((ll)a * b) % mod;
}
int add(int a, int b)
{
	return (a + b) % mod;
}
void mult_matrix(vector<vector<int>>& a, vector<vector<int>>& b)
{
	vector<vector<int>> res(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
				res[i][j] = add(res[i][j], mult(a[i][k], b[k][j]));
		}
	}
	a = res;
}
int main()
{
	ll k;
	cin >> n >> k;
	vector<vector<int>> can(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> can[i][j];
	}
	vector<vector<int>> idn(n, vector<int>(n));
	for (int i = 0; i < n; ++i) idn[i][i] = 1;
	while (k)
	{
		if (k & 1) mult_matrix(idn, can);
		mult_matrix(can, can);
		k /= 2;
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			res= add(res, idn[i][j]);
	}
	cout << res << "\n";
	return 0;
}
