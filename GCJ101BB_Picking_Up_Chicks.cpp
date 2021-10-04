#include<bits/stdc++.h>
using namespace std;

int findMinSwaps(int n, int k, int b, int t, int x[], int v[]) {
	int swaps = 0, slowChicks = 0, counter = 0;

	for (int i = n - 1; i > -1; --i) {
		int reqDistance = b - x[i];
		int maxDistance = t * v[i];
		if (maxDistance >= reqDistance) {
			++counter;
			swaps += slowChicks;
		}
		else ++slowChicks;
		if (counter >= k) return swaps;
	}

	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n, k, b, t;
		cin >> n >> k >> b >> t;
		int* x = new int[n];
		int* v = new int[n];
		for (int i = 0; i < n; ++i) cin >> x[i];
		for (int i = 0; i < n; ++i) cin >> v[i];

		int ans = findMinSwaps(n, k, b, t, x, v);
		if (ans == -1) {
			cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
		}
		else {
			cout << "Case #" << tc << ": " << ans << endl;
		}
	}

	return 0;
}
