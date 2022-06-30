// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int smallestSumSubarray(vector<int>& a) {
        //Code here
        int currentSum = 0;
        int minSum = INT_MAX;

        for (int num : a) {
            currentSum = min(currentSum + num, num);
            minSum = min(minSum, currentSum);
        }

        return minSum;
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

        int ans = ob.smallestSumSubarray(a);

        cout << ans << endl;
    }
}  // } Driver Code Ends