// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    string newIPAdd(string s) {
        //code here.
        int n = s.size();
        string ans("");

        for (int i = 0; i < n; ++i) {
            string ip("");
            while (i < n && s[i] != '.') {
                ip += s[i];
                ++i;
            }
            int j = 0;
            while (ip[j] == '0' && ip.size() > 1) {
                ip.erase(j, 1);
            }
            if (ans.empty()) ans += ip;
            else ans = ans + '.' + ip;
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.newIPAdd(s) << endl;
    }
}

// } Driver Code Ends