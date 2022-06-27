// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> changeBits(int n) {
        // code here
        int bits = ceil(log2(n)) == floor(log2(n)) ? ceil(log2(n)) + 1 : ceil(log2(n));

        return { (1 << bits) - n - 1, (1 << bits) - 1 };
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}  // } Driver Code Ends