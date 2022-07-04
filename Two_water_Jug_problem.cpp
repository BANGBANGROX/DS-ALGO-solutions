// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	int gcd(int a, int b) {
		if (b == 0) return a;

		return gcd(b, a % b);
	}

	int pour(int fromCap, int toCap, int d) {
		int steps = 1;
		int from = fromCap;
		int to = 0;

		while (from != d && to != d) {
			int temp = min(from, toCap - to);
			from -= temp;
			to += temp;
			++steps;
			if (from == d || to == d) return steps;
			if (from == 0) {
				from = fromCap;
				++steps;
			}
			if (to == toCap) {
				to = 0;
				++steps;
			}
		}

		return steps;
	}

public:
	int minSteps(int m, int n, int d) {
		// Code here
		if (m > n) swap(m, n);

		if (d > n || d % gcd(m, n) != 0) return -1;

		return min(pour(m, n, d), pour(n, m, d));
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends