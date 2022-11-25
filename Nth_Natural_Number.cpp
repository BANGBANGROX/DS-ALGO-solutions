//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution {
	typedef long long ll;

public:
	ll findNth(ll n) {
		// code here.
		string ans("");

		while (n > 0) {
			ans += to_string(n % 9);
			n /= 9;
		}

		reverse(ans.begin(), ans.end());

		return stoll(ans);
	}
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, ans;
		cin >> n;
		Solution obj;
		ans = obj.findNth(n);
		cout << ans << endl;
	}
}


// } Driver Code Ends