// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;
class Solution {

	// } Driver Code Ends

public:

	void seive(vector<bool>& prime, int n) {
		for (int i = 2; i < n; ++i) {
			if (prime[i] == 1) {
				for (int j = 2 * i; j < n; j += i) {
					prime[j] = 0;
				}
			}
		}
	}

	string leftShift(string s) {
		int n = s.size();

		char ch = s[0];

		for (int i = 1; i < n; ++i) s[i - 1] = s[i];

		s[n - 1] = ch;

		return s;
	}

	int isCircularPrime(int n) {
		// Code here
		vector<bool> prime(10 * n, 1);

		seive(prime, 10 * n);

		prime[0] = prime[1] = 0;

		string num = to_string(n);

		int len = num.size();

		while (len--) {
			if (!prime[n]) return -1;
			num = leftShift(num);
			n = stoi(num);
		}

		return 1;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.isCircularPrime(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends

