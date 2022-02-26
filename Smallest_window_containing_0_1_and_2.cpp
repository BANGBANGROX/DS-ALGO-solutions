// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int smallestSubstring(string s) {
        // Code here
        int n = s.size();
        int l = 0;
        int minLen = INT_MAX;
        vector<int> count(3);

        for (int i = 0; i < n; ++i) {
            ++count[s[i] - '0'];
            while (count[s[l] - '0'] > 1) {
                --count[s[l] - '0'];
                ++l;
            }
            if (count[0] > 0 && count[1] > 0 && count[2] > 0) minLen = min(minLen, i - l + 1);
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends