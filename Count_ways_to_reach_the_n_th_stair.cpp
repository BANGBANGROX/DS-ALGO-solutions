//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n) {
        // your code here
        if (n == 1) return 1;

        if (n == 2) return 2;

        int a = 1;
        int b = 2;

        for (int i = 3; i <= n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends