// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    string movOnGrid(int r, int c) {
        // code here
        r = (r - 1) % 7;
        c = (c - 1) % 4;

        return r == c ? "ARYA" : "JON";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        Solution ob;
        cout << ob.movOnGrid(r, c) << endl;
    }
    return 0;
}
// } Driver Code Ends