// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minChar(string s) {
		//Write your code here
		string str = s;

		str.push_back('#');
		reverse(s.begin(), s.end());

		s = str + s;

		int n = s.size();
		int i = 1;
		int len = 0;
		vector<int> lps(n);

		while (i < n) {
			if (s[i] == s[len]) {
				++len;
				lps[i] = len;
				++i;
			}
			else {
				if (len == 0) ++i;
				else len = lps[len - 1];
			}
		}

		return (n - 1) / 2 - lps[n - 1];
	}
};


// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.minChar(str);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends