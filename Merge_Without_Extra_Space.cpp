#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int b[], int n, int m) {
	int i = 0, j = 0, k = n - 1;

	while (i <= k && j < m) {
		if (a[i] < b[j]) ++i;
		else {
			swap(a[k], b[j]);
			--k;
			++j;
		}
	}

	sort(a, a + n);
	sort(b, b + m);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		int* a = new int[n], * b = new int[m];
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) cin >> b[i];

		merge(a, b, n, m);

		for (int i = 0; i < n; ++i) cout << a[i] << " ";
		for (int j = 0; j < m; ++j) cout << b[j] << " ";
		cout << endl;
	}

	return 0;
}
