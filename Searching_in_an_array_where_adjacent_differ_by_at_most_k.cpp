#include<bits/stdc++.h>
using namespace std;

int find(int a[], int n, int x, int key) {
	int ind = 0;

	while (ind < n) {
		if (a[ind] == key) return ind;
		ind += max(1, (a[ind] - key) / x);
	}

	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		int x;
		cin >> x;

		cout << find(a, n, abs(a[1] - a[0]), x) << endl;
	}

	return 0;
}