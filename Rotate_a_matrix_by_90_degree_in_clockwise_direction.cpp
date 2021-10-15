#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& m) {
	int n = m.size();

	for (int i = 0; i < n / 2; ++i) {
		for (int j = i; j < n - 1 - i; ++j) {
			int temp = m[i][j];
			m[i][j] = m[n - 1 - j][i];
			m[n - 1 - j][i] = m[n - 1 - i][n - 1 - j];
			m[n - 1 - i][n - 1 - j] = m[j][n - 1 - i];
			m[j][n - 1 - i] = temp;
		}
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<vector<int>> m(n, vector<int>(n));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cin >> m[i][j];
		}

		rotate(m);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cout << m[i][j] << " ";
			cout << endl;
		}
	}

	return 0;
}