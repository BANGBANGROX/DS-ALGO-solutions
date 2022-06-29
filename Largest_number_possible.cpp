// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    string findLargest(int N, int S) {
        // code here
        if (9 * N > S) return "-1";

        if (S == 0) {
            if (N == 1) return "0";
            return "-1";
        }

        int nines = S / 9;
        int left = S % 9;
        string ans("");

        N -= nines;
        
        while (nines > 0) {
            ans += "9";
            --nines;
        }

        if (N == 0) return ans;

        ans += to_string(left);
        --N;

        while (N > 0) {
            ans += "0";
            --N;
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, S;
        cin >> N >> S;

        Solution ob;
        cout << ob.findLargest(N, S) << "\n";
    }
    return 0;
}  // } Driver Code Ends