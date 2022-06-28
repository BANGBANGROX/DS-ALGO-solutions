// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n) {
        // Your code here
        int pos = 1;

        if (m == n) return -1;

        while (m > 0 || n > 0) {
            int bit1 = (m & 1);
            int bit2 = (n & 1);
            if (bit1 != bit2) return pos;
            m >>= 1;
            n >>= 1;
            ++pos;
        }

        return -1;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t; //input number of testcases
    while (t--)
    {
        int m, n;
        cin >> m >> n; //input m and n
        Solution ob;
        cout << ob.posOfRightMostDiffBit(m, n) << endl;
    }
    return 0;
}   // } Driver Code Ends