#include<bits/stdc++.h>
using namespace std;

int solve(int n, int p, int pos[]) {
	--p;

	int res = pos[p];

	for (int steps = 1; steps < n; ++steps) {
		int left = p - steps, right = p + steps;
		if (left > -1 && right < n) {
			if (pos[left] && pos[right]) res += 2;
		}
		else if (left > -1 && pos[left]) ++res;
		else if (right < n && pos[right]) ++res;
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, p;
		cin >> n >> p;
		int* pos = new int[n];
		for (int i = 0; i < n; ++i) cin >> pos[i];

		cout << solve(n, p, pos) << endl;
	}

	return 0;
}