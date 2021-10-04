#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N = 305;
ld p[N][N][N], ev[N][N][N];
// p[a][b][c] is the probablity to reach state (a,b,c) a 1s b 2s and c 3s and ev[a][b][c] is the expected value of the same
int main()
{
	int n;
	cin >> n;
	vector<int> cnt(4);
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		++cnt[x];
	}
	p[cnt[1]][cnt[2]][cnt[3]] = 1; // probablity to reach full is 1
	for (int c = n; c > -1; --c)
	{
		for (int b = n; b > -1; --b)
		{
			for (int a = n; a > -1; --a)
			{
				if (a == 0 && b == 0 && c == 0 || (a + b + c) > n) continue;
				ld p_waste = (ld)(n - (a + b + c)) / n;
				ld ev_waste = p_waste / (1 - p_waste); // expected value for wasting a move is p_waste + p_waste^2 + p_waste^3 + ...
				ev[a][b][c] += ev_waste * p[a][b][c];
				if (a > 0) // remove 1
				{
					ld p_use = (ld)a / (a + b + c);
					p[a - 1][b][c] += p[a][b][c] * p_use;
					ev[a - 1][b][c] += ev[a][b][c] * p_use;
				}
				if (b > 0) // remove 2 increase 1
				{
					ld p_use = (ld)b / (a + b + c);
					p[a + 1][b - 1][c] += p[a][b][c] * p_use;
					ev[a + 1][b - 1][c] += ev[a][b][c] * p_use;
				}
				if (c > 0) // remove 3 increase 2
				{
					ld p_use = (ld)c / (a + b + c);
					p[a][b + 1][c - 1] += p[a][b][c] * p_use;
					ev[a][b + 1][c - 1] += ev[a][b][c] * p_use;
				}
			}
		}
	}
	ld res = ev[0][0][0] + cnt[1] + 2 * cnt[2] + 3 * cnt[3]; // eventually we have to reach (0,0,0) i.e. completely finished but there will be steps to reduce all 1s to 0 
															 //2s to 0 and 3s to 0
	cout << setprecision(10) << fixed << res << "\n";
	return 0;
}
