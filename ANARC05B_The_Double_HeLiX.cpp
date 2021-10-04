#include<bits/stdc++.h>
using namespace std;

int findMaxSum(int a[], int b[], int n, int m) {
	int res = 0, res1 = 0, res2 = 0;
	int ptr1 = 0, ptr2 = 0;

	while (ptr2 < m) {
		res2 += b[ptr2];
		while (ptr1 < n && a[ptr1] < b[ptr2]) {
			res1 += a[ptr1];
			++ptr1;
		}
		if (ptr1 < n && a[ptr1] == b[ptr2]) {
			res1 += a[ptr1];
			res += max(res1, res2);
			res1 = 0;
			res2 = 0;
			++ptr1;
		}
		++ptr2;
	}

	while (ptr1 < n) {
		res1 += a[ptr1];
		++ptr1;
	}

	res += max(res1, res2);

	return res;
}

int main() {
	while (true) {
		int n, m;
		cin >> n;
		if (n == 0) {
			break;
		}
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		cin >> m;
		int* b = new int[m];
		for (int i = 0; i < m; ++i) cin >> b[i];

		cout << findMaxSum(a, b, n, m) << endl;
	}

	return 0;
}