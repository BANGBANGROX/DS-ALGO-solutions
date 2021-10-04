#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char keypad[4][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'} };
int dr[5] = { -1,0,0,1,0 };
int dc[5] = { 0,1,-1,0,0 };

bool isValid(int i, int j) {
	return i > -1 && j > -1 && i < 4 && j < 3 && keypad[i][j] != '*' && keypad[i][j] != '#';
}

ll getCount(int n) {
	if (n == 1) return 10;

	vector<vector<ll>> dp(10, vector<ll>(n + 1)); // dp[i][j] is the result for number starting with i and length j
	ll res = 0;
	for (int i = 0; i < 10; ++i) { // length 1 answer is 1 
		dp[i][1] = 1;
	}

	for (int len = 2; len <= n; ++len) {
		for (int row = 0; row < 4; ++row) {
			for (int col = 0; col < 3; ++col) {
				if (keypad[row][col] == '*' || keypad[row][col] == '#') continue;
				int num = keypad[row][col] - '0';
				for (int i = 0; i < 5; ++i) {
					if (isValid(row + dr[i], col + dc[i])) { // check for top, bottom, left, right number
						int newNum = keypad[row + dr[i]][col + dc[i]] - '0';
						dp[num][len] += dp[newNum][len - 1];
					}
				}
			}
		}
	}
	for (int i = 0; i < 10; ++i) {
		res += dp[i][n];
	}

	return res;
}

int main() {
	int T;

	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		cout << getCount(n) << endl;
	}

	return 0;
}