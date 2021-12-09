// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// return a string formed by compressing string s
// do not print anything

class Solution {
public:

    void generateLPS(string s, vector<int>& lps) {
        int n = s.size(), i = 1, len = 0;

        while (i < n) {
            if (s[i] == s[len]) {
                ++len;
                lps[i] = len;
                ++i;
            }
            else {
                if (len == 0) {
                    lps[i] = 0;
                    ++i;
                }
                else len = lps[len - 1];
            }
        }
    }

    string compress(string s) {
        // Your code goes here
        int n = s.size(), i = n - 1;
        vector<int> lps(n);
        string ans("");

        generateLPS(s, lps);

        while (i > -1) {
            if (i % 2 == 0) {
                ans += s[i];
                --i;
                continue;
            }
            int suffix = lps[i], substring = i + 1;
            bool flag = (suffix * 2 >= substring) && (substring % (substring - suffix) == 0)
                && ((substring / (substring - suffix)) % 2 == 0);
            if (flag) {
                ans += '*';
                i = i / 2 + 1;
            }
            else {
                ans += s[i];
            }
            --i;
        }

        reverse(begin(ans), end(ans));

        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.compress(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends