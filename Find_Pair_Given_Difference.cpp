#include<bits/stdc++.h>
using namespace std;

bool findPair(int a[], int n, int k) {
	int l = 0, r = 1;
	sort(a, a + n);

	while (l < n && r < n && l <= r) {
		int diff = a[r] - a[l];
		if (diff == k) return true;
		else if (diff < k) ++r;
		else ++l;
	}

	return false;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << findPair(a, n, k) << endl;
	}

	return 0;
}