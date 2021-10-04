#include<bits/stdc++.h>
using namespace std;

int setBitCount(int x) {
	int res = 0;

	while (x) {
		++res;
		x = x & (x - 1);
	}

	return res;
}

bool comp(int a, int b) {
	int bitCount1 = setBitCount(a);
	int bitCount2 = setBitCount(b);

	return bitCount1 >= bitCount2;
}

void sortBySetBitCount(int arr[], int n) {
	stable_sort(arr, arr + n, comp);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		sortBySetBitCount(a, n);
		for (int i = 0; i < n; ++i) cout << a[i] << endl;
	}

	return 0;
}