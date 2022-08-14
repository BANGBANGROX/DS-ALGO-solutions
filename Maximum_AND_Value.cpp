//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // Function for finding maximum AND value.
    int maxAND(int nums[], int n) {
        // Your code here
        int ans = 0;

        for (int bit = 31; bit >= 0; --bit) {
            int val = ans | (1 << bit);
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if ((val & nums[i]) == val) {
                    ++cnt;
                }
            }
            if (cnt >= 2) {
                ans |= (1 << bit);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

// Driver function
int main() {
    int t;
    cin >> t;//testcases
    while (t--) {
        int n;
        cin >> n;//input n
        int arr[n + 5], i;

        //inserting elements
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        //calling maxAND() function
        cout << obj.maxAND(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends