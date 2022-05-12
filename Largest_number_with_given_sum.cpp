// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return Largest Number

class Solution
{
public:
	//Function to return the largest possible number of n digits
	//with sum equal to given sum.
	string largestNumber(int n, int sum) {
		// Your code here
		int times = sum / 9;
		int remaining = sum % 9;
		string ans("");

		if (9 * n > sum) return "-1";

		while (times > 0) {
			ans += to_string(9);
			--times;
			--n;
		}

		ans += to_string(remaining);
		--n;

		while (n > 0) {
			ans += to_string(0);
			--n;
		}

		return ans;
	}
};

// { Driver Code Starts.
int main()
{
	//taking testcases
	int t;
	cin >> t;

	while (t--)
	{
		//taking n and sum
		int n, sum;
		cin >> n >> sum;

		Solution obj;
		//function call
		cout << obj.largestNumber(n, sum) << endl;
	}
	return 0;
}  // } Driver Code Ends