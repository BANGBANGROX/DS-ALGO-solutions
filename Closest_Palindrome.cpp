// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	typedef long long int ll;

	ll generatePalindrome(ll num, bool isOdd) {
		string res = to_string(num);
		int n = res.size();
		int l = n - 1;

		if (isOdd) --l;

		while (l >= 0) {
			res += res[l];
			--l;
		}

		return stoll(res);
	}

	ll findMinAbsoluteDiffernce(ll num, ll num1, ll num2, ll num3) {
		ll diff1 = abs(num - num1);
		ll diff2 = abs(num - num2);
		ll diff3 = abs(num - num3);

		if (diff1 < diff2) {
			if (diff1 < diff3) return num1;
			else if (diff1 == diff3) return min(num1, num3);
			return num3;
		}

		if (diff1 == diff2) {
			if (diff1 < diff3) return min(num1, num2);
			return num3;
		}

		if (diff1 > diff2) {
			if (diff2 < diff3) return num2;
			else if (diff2 == diff3) return min(num2, num3);
			return num3;
		}

		return LONG_MAX;
	}

public:
	ll closestPalindrome(ll num) {
		// Code here
		if (num < 10) return num;

		if (log10(num) == floor(log10(num))) return num - 1;

		string stringNum = to_string(num);
		string palindromNum("");
		int n = stringNum.size();
		bool isOdd = n % 2 == 1;

		for (int i = 0; i < n / 2; ++i) {
			palindromNum += stringNum[i];
		}

		if (isOdd) palindromNum += stringNum[n / 2];

		ll ans1 = generatePalindrome(stoll(palindromNum), isOdd);
		ll ans2 = generatePalindrome(stoll(palindromNum) - 1, isOdd);
		ll ans3 = generatePalindrome(stoll(palindromNum) + 1, isOdd);

		return findMinAbsoluteDiffernce(num, ans1, ans2, ans3);
	}

};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends