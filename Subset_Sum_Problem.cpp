//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    bool isSubsetSum(vector<int>& nums, int sum) {
        // code here
        vector<bool> dp(sum + 1);

        dp[0] = true;

        for (int num : nums) {
            for (int i = sum; i > 0; --i) {
                if (i >= num) {
                    dp[i] = dp[i] | dp[i - num];
                }
            }
        }

        return dp[sum];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}

// } Driver Code Ends