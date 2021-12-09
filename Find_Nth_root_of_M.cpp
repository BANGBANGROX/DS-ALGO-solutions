// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int NthRoot(int n, int m) {
		if (n == 1 || m == 1) return m;

		int ans = 1;

		for (int i = 2; i * i <= m; ++i) {
			int cnt = 0;
			while (m % i == 0) {
				m /= i;
				++cnt;
			}
			if (cnt % n != 0) return -1;
			ans *= (pow(i, cnt / n));
		}

		return ans == 1 ? -1 : ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends