// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minVal(int a, int b) {
        // code here
        int setBits = __builtin_popcount(b);
        vector<int> bits(32);
        int ans = 0;

        for (int i = 31; i >= 0; --i) {
            int bit = (a & (1 << i));
            if (bit == 0 || setBits == 0) continue;
            bits[i] = 1;
            --setBits;
        }

        for (int i = 0; i < 31 && setBits > 0; ++i) {
            if (bits[i] == 0) {
                bits[i] = 1;
                --setBits;
            }
        }

        for (int i = 31; i >= 0; --i) {
            ans = ans * 2 + bits[i];
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends