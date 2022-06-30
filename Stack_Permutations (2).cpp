// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int isStackPermutation(int n, vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int j = 0;

        for (int i = 0; i < n; ++i) {
            s.push(nums1[i]);
            while (!s.empty() && s.top() == nums2[j]) {
                s.pop();
                ++j;
            }
        }

        return s.empty();
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isStackPermutation(n, a, b) << endl;
    }

    return 0;
}  // } Driver Code Ends