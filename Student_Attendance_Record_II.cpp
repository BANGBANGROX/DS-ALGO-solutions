#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int checkRecord(int n) {
		const int mod = 1e9 + 7;
		int a1 = 1; // 00
		int a2 = 1; // 01
		int a3 = 0; // 02
		int a4 = 1; // 10
		int a5 = 0; // 11
		int a6 = 0; // 12

		for (int i = 1; i < n; ++i) {
			int newA1 = ((long)a1 + a2 + a3) % mod;
			int newA2 = a1;
			int newA3 = a2;
			int newA4 = ((long)a1 + a2 + a3 + a4 + a5 + a6) % mod;
			int newA5 = a4;
			int newA6 = a5;
			a1 = newA1;
			a2 = newA2;
			a3 = newA3;
			a4 = newA4;
			a5 = newA5;
			a6 = newA6;
		}

		return ((long)a1 + a2 + a3 + a4 + a5 + a6) % mod;
	}
};


int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		Solution solution;
		cout << solution.checkRecord(n) << endl;
	}

	return 0;
}