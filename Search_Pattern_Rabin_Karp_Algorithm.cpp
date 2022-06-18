// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void generateLPS(string s, vector<int>& lps) {
        int n = s.size();
        int i = 1;
        int len = 0;

        while (i < n) {
            if (s[i] == s[len]) {
                ++len;
                lps[i] = len;
                ++i;
            }
            else {
                if (len == 0) ++i;
                else len = lps[len - 1];
            }
        }
    }

public:
    vector <int> search(string pat, string txt) {
        //code here.
        int m = pat.size();
        int n = txt.size();
        int i = 0;
        int j = 0;
        vector<int> lps(m);
        vector<int> ans;

        generateLPS(pat, lps);

        while (i < n) {
            if (pat[j] == txt[i]) {
                ++i;
                ++j;
            }
            if (j == m) {
                ans.push_back(i - j);
                j = lps[j - 1];
                continue;
            }
            if (pat[j] != txt[i]) {
                if (j == 0) ++i;
                else j = lps[j - 1];
            }
        }

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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends