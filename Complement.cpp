//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> findRange(string s, int n) {
        // code here
        int start = -1;
        int end = -1;
        int l = 0;
        int currentCount = 0;
        int maxCount = 0;
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            currentCount += (s[i] == '0' ? 1 : -1);
            if (currentCount < 0) {
                currentCount = 0;
                l = i + 1;
            }
            else if (currentCount > maxCount) {
                start = l;
                end = i;
                maxCount = currentCount;
            }
        }

        if (end == -1) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(start + 1);
            ans.push_back(end + 1);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        }
        else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends