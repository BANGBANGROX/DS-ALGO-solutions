//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution {
    unordered_map<string, bool> dp;

public:
    bool isScramble(string s1, string s2) {
        //code here
        if (s1.compare(s2) == 0) return true;

        if (s1.size() != s2.size()) return false;

        string key = s1 + "-" + s2;

        if (dp.find(key) != dp.end()) return dp[key];

        int n = (int) s1.size();
        bool res = false;

        for (int i = 1; i < n; ++i) {
            res |= (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                    isScramble(s1.substr(i), s2.substr(i))) ||
                   (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                    isScramble(s1.substr(i), s2.substr(0, n - i)));
            if (res) break;
        }

        return dp[key] = res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1, S2;
        cin >> S1 >> S2;
        Solution ob;

        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends