#include<bits/stdc++.h>
using namespace std;

int countWays(int N, string s) {
	const int mod = 1003;
	vector<char> symbol, op;
	for (int i = 0; i < N; ++i) {
		if (s[i] == 'T' || s[i] == 'F') {
			symbol.push_back(s[i]);
		}
		else {
			op.push_back(s[i]);
		}
	}
	int n = symbol.size();
	vector<vector<int>> T(n, vector<int>(n));
	vector<vector<int>> F(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		T[i][i] = (symbol[i] == 'T');
		F[i][i] = (symbol[i] == 'F');
	}

	for (int gap = 1; gap < n; ++gap) {
		for (int i = 0, j = gap; j < n; ++i, ++j) {
			for (int g = 0; g < gap; ++g) {
				int k = i + g;
				int tik = (T[i][k] + F[i][k]) % mod;
				int tkj = (T[k + 1][j] + F[k + 1][j]) % mod;
				if (op[k] == '&') {
					T[i][j] = (T[i][j] + (T[i][k] * T[k + 1][j]) % mod) % mod;
					F[i][j] = (F[i][j] + (tik * tkj) % mod - (T[i][k] * T[k + 1][j]) % mod + mod) % mod;
				}
				else if (op[k] == '|') {
					T[i][j] = (T[i][j] + (tik * tkj) % mod - (F[i][k] * F[k + 1][j]) % mod + mod) % mod;
					F[i][j] = (F[i][j] + (F[i][k] * F[k + 1][j]) % mod) % mod;
				}
				else if (op[k] == '^') {
					T[i][j] = (T[i][j] + (T[i][k] * F[k + 1][j]) % mod + (F[i][k] * T[k + 1][j]) % mod) % mod;
					F[i][j] = (F[i][j] + (T[i][k] * T[k + 1][j]) % mod + (F[i][k] * F[k + 1][j]) % mod) % mod;
				}
			}
		}
	}

	return T[0][n - 1];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> n >> s;
		cout << countWays(n, s) << endl;
	}

	return 0;
}
