// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    int wineSelling(vector<int>& a) {
        //Code here.
        int sum = 0;
        int ans = 0;

        for (int num : a) {
            sum += num;
            ans += abs(sum);
        }

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

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        int ans = ob.wineSelling(a);

        cout << ans << endl;
    }
}  // } Driver Code Ends