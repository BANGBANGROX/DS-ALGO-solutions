#include<bits/stdc++.h>
using namespace std;

int trailingZeroes(int n) {
	int res = 0;

	while (n) {
		res += (n / 5);
		n /= 5;
	}

	return res;
}

int findNum(int zeroes) {
	int l = 0, r = 1e9, ans = -1;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (trailingZeroes(mid) >= zeroes) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		cout << findNum(n) << endl;
	}

	return 0;
}