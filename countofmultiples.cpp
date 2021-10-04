#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int findmultiples(vector<int>& a, int n, int k)
{
	int res = 0;
	for (int curr = k; curr < N; curr += k)
	{
		if (binary_search(a.begin(), a.end(), curr)) ++res;
	}
	return res;
}
int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	while (q--)
	{
		int k;
		cin >> k;
		cout << findmultiples(a, n, k) << "\n";
	}
	return 0;
}