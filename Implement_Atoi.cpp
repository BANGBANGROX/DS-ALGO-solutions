// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
	/*You are required to complete this method */
	int atoi(string str) {
		//Your code here
		bool sign = str[0] != '-';
		int ans = 0;

		if (!sign) {
			str = str.substr(1);
		}

		for (int i = 0; i < (int)str.size(); ++i) {
			if (!isdigit(str[i])) return -1;
			ans = ans * 10 + (str[i] - '0');
		}

		if (!sign) ans *= -1;

		return ans;
	}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		Solution ob;
		cout << ob.atoi(s) << endl;
	}
}  // } Driver Code Ends