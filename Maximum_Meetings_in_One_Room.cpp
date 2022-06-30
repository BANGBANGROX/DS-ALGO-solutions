// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> maxMeetings(int n, vector<int>& start, vector<int>& end) {
        vector<vector<int>> timings;
        vector<vector<int>> res;
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            timings.push_back({ start[i],end[i],i });
        }

        sort(timings.begin(), timings.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[2] < b[2];
            });


        for (vector<int>& a : timings) {
            if (res.empty() || res.back()[1] < a[0]) {
                res.push_back(a);
            }
        }

        for (vector<int>& a : res) {
            ans.push_back(a[2] + 1);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> S(n), F(n);
        for (int i = 0; i < n; i++) {
            cin >> S[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> F[i];
        }
        Solution ob;
        vector<int> ans = ob.maxMeetings(n, S, F);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i != ans.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends