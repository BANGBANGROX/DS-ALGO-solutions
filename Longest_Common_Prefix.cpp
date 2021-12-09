// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> longestCommonPrefix(string s, string t) {
        int start = -1, end = -1, i = 0, j = 0, n = s.size(), m = t.size();

        while (i < n && j < m) {
            if (s[i] == t[j]) {
                start = i;
                while (i < n && j < m && s[i] == t[j]) {
                    ++i;
                    ++j;
                }
                if (i > end) end = i;
            }
            else {
                i = 0;
                ++j;
            }
        }

        return { start,end };
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        Solution ob;
        vector<int> p;
        p = ob.longestCommonPrefix(str1, str2);
        if (p[0] == -1)
            cout << "-1\n";

        else
            cout << p[0] << " " << p[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
