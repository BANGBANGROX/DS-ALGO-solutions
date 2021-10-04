#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll val, int a[], int n, int m) {
	int cnt = 1;
	ll sum = 0;

	for (int i = 0; i < n; ++i) {
		if (a[i] > val) return false;
		if (sum + a[i] > val) {
			++cnt;
			if (cnt > m) return false;
			sum = a[i];
		}
		else sum += a[i];
	}

	return true;
}

int findPages(int a[], int n, int m) {
	ll l = 0, r = 1e12, ans = -1;

	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid, a, n, m)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << findPages(a, n, m) << endl;
	}

	return 0;
}