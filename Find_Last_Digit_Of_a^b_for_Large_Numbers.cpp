// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int getLastDigit(string a, string b) {
        // code here
        int n = b.size(), mod = 0, dig = a.back() - '0';

        if (dig == 0) return 0;

        if (b.compare("0") == 0) return 1;

        for (int i = 0; i < n; ++i) {
            mod = ((b[i] - '0') + mod * 10) % 4;
        }

        int exp = mod == 0 ? 4 : mod;

        return (int)pow(dig, exp) % 10;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;

        cin >> a >> b;

        Solution ob;
        cout << ob.getLastDigit(a, b) << endl;
    }
    return 0;
}  // } Driver Code Ends
