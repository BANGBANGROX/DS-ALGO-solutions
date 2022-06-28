// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	//Function to swap odd and even bits.
	unsigned int swapBits(unsigned int n) {
		// Your code here
		unsigned int evenBit = n & 0xAAAAAAAA;
		unsigned int oddBit = n & 0x55555555;

		evenBit >>= 1;
		oddBit <<= 1;

		return evenBit | oddBit;
	}
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin >> t;//testcases
	while (t--)
	{
		unsigned int n;
		cin >> n;//input n

		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends