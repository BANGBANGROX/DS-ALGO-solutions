// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int maxSubStr(string s) {
		//Write your code here
		int currentSum = 0;
		int ans = 0;
		
		for (char ch : s) {
			if (ch == '0') ++currentSum;
			else --currentSum;
			if (currentSum == 0) {
				++ans;
			}
		}

		return currentSum == 0 ? ans : -1;
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
		int ans = ob.maxSubStr(str);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends