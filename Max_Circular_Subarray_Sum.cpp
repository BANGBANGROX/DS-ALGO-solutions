//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int nums[], int n) {
        // your code here
        int minCurrentSum = 0;
        int maxCurrentSum = 0;
        int minSum = INT_MAX;
        int maxSum = INT_MIN;
        int totalSum = 0;

        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
            maxCurrentSum = max(maxCurrentSum + nums[i], nums[i]);
            minCurrentSum = min(minCurrentSum + nums[i], nums[i]);
            maxSum = max(maxSum, maxCurrentSum);
            minSum = min(minSum, minCurrentSum);
        }

        return totalSum == minSum ? maxSum : max(maxSum, totalSum - minSum);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;

    //testcases
    cin>> T;

    while (T--)
    {
        int num;

        //size of array
        cin>>num;
        int arr[num];

        //inserting elements
        for(int i = 0; i<num; i++)
            cin>>arr[i];

        Solution ob;
        //calling function
        cout << ob.circularSubarraySum(arr, num) << endl;

    }

    return 0;
}
// } Driver Code Ends