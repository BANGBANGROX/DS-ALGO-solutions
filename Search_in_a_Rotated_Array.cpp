#include<bits/stdc++.h>
using namespace std;

int search(int a[], int l, int h, int key) {
	if (l > h) return -1;
	
	int mid = (l + h) / 2;
	if (a[mid] == key) return mid;
	if (a[mid] >= a[l]) {
		if (key >= a[l] && key <= a[mid]) return search(a, l, mid - 1, key);
		return search(a, mid + 1, h, key);
	}
	if (key >= a[mid] && key <= a[h]) return search(a, mid + 1, h, key);
	return search(a, l, mid - 1, key);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << search(a, 0, n - 1, x) << endl;
	}

	return 0;
}