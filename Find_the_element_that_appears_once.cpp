//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    int search(int nums[], int n) {
        //code
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            ans ^= nums[i];
        }

        return ans;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t, len;
    cin >> t;
    while (t--)
    {
        cin >> len;
        int* arr = new int[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.search(arr, len) << '\n';
    }
    return 0;
}

// } Driver Code Ends