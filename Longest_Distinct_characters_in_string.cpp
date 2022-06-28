// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars(string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars(S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars(string s) {
    // your code here
    int l = 0;
    int ans = 0;
    int n = s.size();
    vector<int> count(26);

    for (int r = 0; r < n; ++r) {
        ++count[s[r] - 'a'];
        while (count[s[r] - 'a'] > 1) {
            --count[s[l] - 'a'];
            ++l;
        }
        ans = max(ans, r - l + 1);
    }

    return ans;
}