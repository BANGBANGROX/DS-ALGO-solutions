// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int longestSubstring(string s) {
        // code here
        int ans = 0;
        int n = s.size();
        unordered_map<int, int> mapMask;
        int mask = 0;

        mapMask[mask] = -1;

        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            mask ^= (1 << idx);
            if (mapMask[mask] != 0) {
                ans = max(ans, i - mapMask[mask]);
            }
            else {
                mapMask[mask] = i;
            }
            for (int j = 0; j < 26; ++j) {
                int newMask = mask ^ (1 << j);
                if (mapMask[newMask] != 0) {
                    ans = max(ans, i - mapMask[newMask]);
                }
            }
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
    }
    return 0;
}  // } Driver Code Ends