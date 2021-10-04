#include<bits/stdc++.h>
using namespace std;

int getPairsCount(int a[], int n, int k) {
	map<int, int> m;
	for (int i = 0; i < n; ++i) m[a[i]]++;
	int res = 0;

	for (int i = 0; i < n; ++i) {
		if (m.find(k - a[i]) == m.end()) continue;
		res += m[k - a[i]];
		if (k - a[i] == a[i]) --res;
	}

	return res / 2;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << getPairsCount(a, n, k) << endl;
	}

	return 0;
}