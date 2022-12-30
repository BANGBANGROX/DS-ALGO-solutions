//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int getCount(int n) {
        // code here
        int ans = 0;

        for (int i = 1; i * (i - 1) / 2 < n; ++i) {
            if ((n - i * (i - 1) / 2) % i == 0) ++ans;
        }

        return ans - 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.getCount(N) << endl;
    }
    return 0;
}
// } Driver Code Ends