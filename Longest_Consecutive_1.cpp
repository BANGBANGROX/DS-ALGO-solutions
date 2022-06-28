// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution {
public:
	int maxConsecutiveOnes(int num) {
		// code here
		int ans = 0;
		int currentSum = 0;

		while (num > 0) {
			int bit = (num & 1);
			if (bit == 1) ++currentSum;
			else {
				ans = max(ans, currentSum);
				currentSum = 0;
			}
			num >>= 1;
		}

		ans = max(ans, currentSum);

		return ans;
	}
};


// { Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin >> t;//testcases
	while (t--)
	{
		int n;
		cin >> n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout << obj.maxConsecutiveOnes(n) << endl;
	}
	return 0;
}  // } Driver Code Ends