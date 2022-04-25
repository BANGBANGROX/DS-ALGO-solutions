// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    string remove(string s) {
        // code here

        while (true) {
            int n = s.size();
            int i = 0;
            string ans("");
            while (i < n) {
                int j = i;
                while (j < n && s[i] == s[j]) ++j;
                if (j == i + 1) ans += s[i];
                i = j;
            }
            if (s.size() == ans.size()) break;
            s = ans;
        }

        return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends