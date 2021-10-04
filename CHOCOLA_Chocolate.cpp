#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findMinCost(int n, int m, int X[], int Y[]) {
	int h = 1, v = 1, i = 0, j = 0;
	ll minCost = 0, total = 0;

	sort(X, X + n, greater<int>());
	sort(Y, Y + m, greater<int>());

	while (i < n && j < m) {
		if (X[i] > Y[j]) {
			minCost += (ll)X[i] * v;
			++h;
			++i;
		}
		else {
			minCost += (ll)Y[j] * h;
			++v;
			++j;
		}
	}
	while (i < n) {
		total += X[i];
		++i;
	}
	minCost += total * v;
	total = 0;
	while (j < m) {
		total += Y[j];
		++j;
	}
	minCost += total * h;

	return minCost;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		--n;
		--m;
		int* a = new int[n];
		int* b = new int[m];
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) cin >> b[i];

		cout << findMinCost(n, m, a, b) << endl;
	}

	return 0;
}

