//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string lexicographicallySmallest(string s, int k) {
        // code here
        stack<int> st;
        string ans("");
        int n = s.size();

        if ((n & (n - 1)) == 0) k /= 2;
        else k *= 2;

        if (k >= n) return "-1";

        for (char ch : s) {
            while (k > 0 && !st.empty() && st.top() > ch) {
                st.pop();
                --k;
            }
            st.push(ch);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            --k;
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends