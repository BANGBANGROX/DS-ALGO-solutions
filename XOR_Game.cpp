// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int xorCal(int k) {
        // code here
        if (k == 1) return 2;

        ++k;

        double x = log2(k);

        if (x == floor(x)) return (k / 2 - 1);
        
        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;

        Solution ob;
        cout << ob.xorCal(k) << "\n";
    }
    return 0;
}  // } Driver Code Ends