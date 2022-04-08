// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	string LCP(string words[], int n) {
		// code here
		string minString = words[0];
		int ans = INT_MAX;

		for (int i = 1; i < n; ++i) {
			if (minString.size() > words[i].size()) {
				minString = words[i];
			}
		}

		for (int i = 0; i < n; ++i) {
			int j = 0;
			while (j < minString.size() && words[i][j] == minString[j]) ++j;
			ans = min(ans, j);
			if (ans == 0) return "";
		}

		return minString.substr(0, ans);
	}
};

// { Driver Code Starts.

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string* arr = new string[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		Solution ob;
		cout << ob.LCP(arr, n) << endl;
	}
	return 0;
}  // } Driver Code Ends