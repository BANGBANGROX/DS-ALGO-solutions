//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int maxValue(int nums[], int n) {
        // code here
        int max1 = INT_MIN;
        int min1 = INT_MAX;
        int max2 = INT_MIN;
        int min2 = INT_MAX;

        for (int i = 0; i < n; ++i) {
            max1 = max(max1, nums[i] + i);
            min1 = min(min1, nums[i] + i);
            max2 = max(max2, i - nums[i]);
            min2 = min(min2, i - nums[i]);
        }

        return max(max1 - min1, max2- min2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;

        int arr[N];

        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxValue(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends