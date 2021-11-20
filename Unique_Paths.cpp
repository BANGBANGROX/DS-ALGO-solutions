#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int uniquePaths(int m, int n) {
	ll ans = 1;

	for (int i = 1; i < n; ++i) {
		ans *= (1LL * m + i - 1);
		ans /= i;
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;

		cout << uniquePaths(m, n) << endl;
	}
}