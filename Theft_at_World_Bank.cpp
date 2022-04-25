// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	typedef long long ll;
	typedef long double ld;

public:
	ld maximumProfit(int n, ll c, vector<ll> w, vector<ll> p) {
		// Code here.
		vector<pair<ll, ll>> items(n);
		ld ans = 0;

		for (int i = 0; i < n; ++i) {
			items[i] = { p[i],w[i] };
		}

		sort(items.begin(), items.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
			return (ld)a.first / a.second > (ld)b.first / b.second;
			});

		for (const pair<ll, ll>& item : items) {
			if (sqrt(item.second) == floor(sqrt(item.second))) continue;
			if (c >= item.second) {
				ans += item.first;
				c -= item.second;
			}
			else {
				ans += ((ld)c / (ld)item.second) * item.first;
				break;
			}
		}

		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for (int i = 0; i < n; i++) {
			cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends