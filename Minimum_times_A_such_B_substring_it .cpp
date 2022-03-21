// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    bool isSubstring(string a, string b) {
        int m = a.size();
        int n = b.size();

        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (; j < n; ++j) {
                if (a[i] != b[j]) break;
                ++i;
            }
            if (j == n) return true;
        }

        return false;
    }

public:
    int minRepeats(string a, string b) {
        // code here
        int ans = 1;
        string s = a;

        while (s.size() < b.size()) {
            s += a;
            ++ans;
        }

        if (isSubstring(s, b)) return ans;

        if (isSubstring(s + a, b)) return ans + 1;

        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}  // } Driver Code Ends