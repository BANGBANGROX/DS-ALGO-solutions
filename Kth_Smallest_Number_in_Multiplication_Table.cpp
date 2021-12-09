#include<bits/stdc++.h>
using namespace std;

bool countNums(int val, int m, int n, int k) {
	int cnt = 0;

	for (int i = 1; i <= m; ++i) {
		cnt += min(val / i, n);
	}

	return cnt >= k;
}

int findKthNumber(int m, int n, int k) {
	int l = 1, r = m * n;

	while (l < r) {
		int mid = (l + ((r - l) >> 2));
		if (countNums(mid, m, n, k)) r = mid;
		else l = mid + 1;
	}

	return l;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n, k;
		cin >> m >> n >> k;

		cout << findKthNumber(m, n, k) << endl;
	}

	return 0;
}
