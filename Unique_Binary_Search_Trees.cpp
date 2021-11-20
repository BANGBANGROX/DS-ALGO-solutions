#include<bits/stdc++.h>
using namespace std;

int numTrees(int n) {
	long long ans = 1;

	for (int i = 1; i <= n; ++i) {
		ans *= (long long)(n + (long long)i);
		ans /= (long long)i;
	}
	ans /= (long long)(n + 1LL * 1);

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		cout << numTrees(n) << endl;
	}

	return 0;
}
