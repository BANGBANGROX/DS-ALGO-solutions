//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
    bool isEqual(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; ++i) {
            if (a[i] != b[i]) return false;
        }

        return true;
    }

public:
    int search(string pattern, string text) {
        // code here
        int m = pattern.size();
        int n = text.size();

        if (m > n) return 0;

        int l = 0;
        int r = m - 1;
        int ans = 0;
        vector<int> countP(26);
        vector<int> countT(26);

        for (char ch : pattern) {
            ++countP[ch - 'a'];
        }

        for (int i = l; i <= r; ++i) {
            ++countT[text[i] - 'a'];
        }

        while (r < n) {
            if (isEqual(countP, countT)) ++ans;
            --countT[text[l] - 'a'];
            ++l;
            ++r;
            if (r < n) ++countT[text[r] - 'a'];
        }

        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends