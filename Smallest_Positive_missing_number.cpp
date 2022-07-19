//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int nums[], int n) {
        // Your code here
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};

//{ Driver Code Starts.

int main() {

    //taking testcases
    int t;
    cin >> t;
    while (t--) {

        //input number n
        int n;
        cin >> n;
        int* arr = new int[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)cin >> arr[i];

        Solution ob;
        //calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends