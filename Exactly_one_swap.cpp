// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    typedef long long ll;
public:
    ll countStrings(string s)
    {
        // code here
        ll ans = 0;
        int n = s.size();
        bool sameChosen = false;
        vector<int> count(26);

        for (char& c : s) {
            ++count[c - 'a'];
        }

        for (int i = 0; i < n; ++i) {
            if (count[s[i] - 'a'] == 1) {
                ans += ((ll)n - i - 1);
                --count[s[i] - 'a'];
                continue;
            }
            ans += ((ll)n - i - count[s[i] - 'a']);
            if (!sameChosen) {
                ++ans;
                sameChosen = true;
            }
            --count[s[i] - 'a'];
        }

        return ans;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout << ans << endl;
    }
    return 0;
}   // } Driver Code Ends