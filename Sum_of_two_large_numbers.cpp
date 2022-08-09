//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    string findSum(string x, string y) {
        // Your code goes here
        int carry = 0;
        int i = 0;
        int j = 0;

        while (x[i] == '0') x.erase(i, 1);

        while (y[j] == '0') y.erase(i, 1);

        int m = x.size();
        int n = y.size();

        if (n > m) return findSum(y, x);

        if (x.empty()) x = "0";
        if (y.empty()) y = "0";

        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());

        while (i < n) {
            int val = (x[i] - '0') + (y[j] - '0') + carry;
            x[i] = char(val % 10 + '0');
            carry = val / 10;
            ++i;
            ++j;
        }

        while (i < m) {
            int val = x[i] - '0' + carry;
            x[i] = char(val % 10 + '0');
            carry = val / 10;
            ++i;
        }
        
        if (carry > 0) x.push_back(char(carry + '0'));

        reverse(x.begin(), x.end());

        return x;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends