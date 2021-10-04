#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], n;
int MAXXOR()
{
	int maxx = 0, mask = 0;
	set<int> s;
	for (int i = 31; i > -1; i--)
	{
		mask |= (1 << i);
		for (int j = 0; j < n; j++)
			s.insert(a[j] & mask);
		int nmaxx = maxx|(1 << i);
		for (int pref : s)
		{
			if (s.count(pref ^ nmaxx))
			{
				maxx = nmaxx;
				break;
			}
		}
		s.clear();
	}
	return maxx;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << MAXXOR() << "\n";
	return 0;
}