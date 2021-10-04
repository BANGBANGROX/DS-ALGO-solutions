#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int rightmostNonZeroDigit(int n, int a[]) {
	int count5 = 0, ans = 1;

	for (int i = 0; i < n; ++i) {
		while (a[i] > 0 && a[i] % 5 == 0) {
			a[i] /= 5;
			++count5;
		}
	}
	for (int i = 0; i < n; ++i) {
		while (a[i] > 0 && a[i] % 2 == 0 && count5 > 0) {
			a[i] /= 2;
			--count5;
		}
		ans = (ans * a[i]) % 10;
	}

	if (count5) {
		ans = (ans * 5) % 10;
	}
	if (!ans) ans = -1;

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << rightmostNonZeroDigit(n, a) << endl;
	}

	return 0;
}
